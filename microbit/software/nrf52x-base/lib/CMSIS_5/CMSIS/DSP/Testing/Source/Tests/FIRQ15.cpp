#include "FIRQ15.h"
#include <stdio.h>
#include "Error.h"

#define SNR_THRESHOLD 59

#define ABS_ERROR_Q15 ((q15_t)2)

#if defined(ARM_MATH_MVEI)
static __ALIGNED(8) q15_t coeffArray[32];
#endif 

    void FIRQ15::test_fir_q15()
    {
        

        const int16_t *configp = configs.ptr();
        q15_t *statep = state.ptr();
        const q15_t *orgcoefsp = coefs.ptr();

        const q15_t *coefsp;
        const q15_t *inputp = inputs.ptr();
        q15_t *outp = output.ptr();

        int i;
#if defined(ARM_MATH_MVEI)
        int j;
#endif
        int blockSize;
        int numTaps;

        /*

        Python script is generating different tests with
        different blockSize and numTaps.

        We loop on those configs.

        */
        for(i=0; i < configs.nbSamples(); i += 2)
        {
           blockSize = configp[0];
           numTaps = configp[1];

#if defined(ARM_MATH_MVEI)
           /* Copy coefficients and pad to zero 
           */
           memset(coeffArray,0,32);
           for(j=0;j < numTaps; j++)
           {
              coeffArray[j] = orgcoefsp[j];
           }
   
           coefsp = coeffArray;
#else
           coefsp = orgcoefsp;
#endif


           /*

           The filter is initialized with the coefs, blockSize and numTaps.

           */
           arm_fir_init_q15(&this->S,numTaps,coefsp,statep,blockSize);

           /*

           Input pointer is reset since the same input pattern is used

           */
           inputp = inputs.ptr();

       
           /*
           
           Python script is filtering a 2*blockSize number of samples.
           We do the same filtering in two pass to check (indirectly that
           the state management of the fir is working.)

           */
           arm_fir_q15(&this->S,inputp,outp,blockSize);
           outp += blockSize;

           inputp += blockSize;
           arm_fir_q15(&this->S,inputp,outp,blockSize);
           outp += blockSize;

           configp += 2;
           orgcoefsp += numTaps;


        }

        ASSERT_EMPTY_TAIL(output);

        ASSERT_SNR(output,ref,(q15_t)SNR_THRESHOLD);

        ASSERT_NEAR_EQ(output,ref,ABS_ERROR_Q15);

    } 

 
    void FIRQ15::setUp(Testing::testID_t id,std::vector<Testing::param_t>& params,Client::PatternMgr *mgr)
    {
      
       
       switch(id)
       {
        case FIRQ15::TEST_FIR_Q15_1:
          
        break;

       }
      

       inputs.reload(FIRQ15::FIRINPUTS_Q15_ID,mgr);
       coefs.reload(FIRQ15::FIRCOEFS_Q15_ID,mgr);
       configs.reload(FIRQ15::FIRCONFIGS_S16_ID,mgr);
       ref.reload(FIRQ15::FIRREFS_Q15_ID,mgr);

       output.create(ref.nbSamples(),FIRQ15::OUT_Q15_ID,mgr);
       /* Max blockSize + numTaps as generated by Python script 
          numTaps may be increased by 1 by Python script to force it to even values
          */
       state.create(41,FIRQ15::OUT_Q15_ID,mgr);
    }

    void FIRQ15::tearDown(Testing::testID_t id,Client::PatternMgr *mgr)
    {
        output.dump(mgr);
    }
