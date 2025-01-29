#include <stdio.h>

// Define states
typedef enum {
    STATE_RED,
    STATE_YELLOW,
    STATE_GREEN,
    STATE_COUNT // Number of states
} State;

// Define events
typedef enum {
    EVENT_TIMER,
    EVENT_COUNT // Number of events
} Event;

// State transition table
State state_transition_table[STATE_COUNT][EVENT_COUNT] = {
    // STATE_RED transitions
    { STATE_GREEN },   // EVENT_TIMER
    
    // STATE_YELLOW transitions
    { STATE_RED },     // EVENT_TIMER
    
    // STATE_GREEN transitions
    { STATE_YELLOW }   // EVENT_TIMER
};

// State action functions
void action_red() {
    printf("Light is RED. Stop.\n");
}

void action_yellow() {
    printf("Light is YELLOW. Prepare to stop.\n");
}

void action_green() {
    printf("Light is GREEN. Go.\n");
}

// Array of state action functions
void (*state_actions[STATE_COUNT])() = {
    action_red,
    action_yellow,
    action_green
};

// Current state
State current_state = STATE_RED;

void handle_event(Event event) {
    if (event >= EVENT_COUNT) {
        printf("Invalid event.\n");
        return;
    }

    // Get the next state from the transition table
    State next_state = state_transition_table[current_state][event];

    // Transition to the next state and perform the state action
    current_state = next_state;
    state_actions[current_state]();
}

int main() {
    // Initial state action
    state_actions[current_state]();

    // Simulate events
    handle_event(EVENT_TIMER); // Transition to GREEN
    handle_event(EVENT_TIMER); // Transition to YELLOW
    handle_event(EVENT_TIMER); // Transition to RED

    return 0;
}
