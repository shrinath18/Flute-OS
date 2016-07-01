
//This function is called from boot.s
int main(struct multiboot *mboot_ptr)
{
    
    print("Hello World!",7,7);
    return 0xDEADBABA;
}

void print(char * message,int start_x,int start_y){
    int index = start_x*80 + start_y; 
    /*
    VGA memory starts at 0xB8000 and writing into this location will print on the screen
   */
    unsigned short * start_position = (unsigned short *)0xB8000 + index; 
    unsigned short attribute = 14;
    unsigned short character = message[0];
    int i = 1;
    while(character != '\0'){
     *start_position = character | (attribute << 8);
     character = message[i];
     i++;
     start_position += 1;
    }

}
