
int main(struct multiboot *mboot_ptr)
{
    
    print("Hello World");
    return 0xDEADBABA;
}

void print(char * message){
    unsigned short * where_to_print = (unsigned short *)0xB8000 + 323;//VGA memory starts at 0xB8000 
    unsigned short attribute = 14;
    unsigned short character = message[0];
    int i = 1;
    while(character != '\0'){
     *where_to_print = character | (attribute << 8);
     character = message[i];
     i++;
     where_to_print += 1;
    }

}
