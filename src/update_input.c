unsigned short button_input_old, buttons_changed, button_input;

void update_input() {
    unsigned short mask = 0x3ff & ~(*(unsigned short*)0x04000130); 
    buttons_changed = mask & ~button_input_old;

    button_input = mask;
    button_input_old = mask;
}