#ifndef _BUFFER_H_DEFINED_
#define _BUFFER_H_DEFINED_

typedef int buffer_item;

#define BUFFER_SIZE 5

bool buffer_insert_item( buffer_item item );

bool buffer_remove_item( buffer_item *item );

#endif // _BUFFER_H_DEFINED_


int main(int argc, char *argv[]) {

do { 
        /* produce an item in next_produced */ 
           
        wait(empty); 
        wait(mutex); 
           
        /* add next produced to the buffer */ 
         
        signal(mutex); 
        signal(full); 
     } while (true);


// Producer // 
while (true) {
	/* produce an item in next produced */ 
	
	while (counter == BUFFER_SIZE) ; 
		/* do nothing */ 
	buffer[in] = next_produced; 
	in = (in + 1) % BUFFER_SIZE; 
	counter++; 
} 

// Consumer 

while (true) {
	while (counter == 0) 
		; /* do nothing */ 
	next_consumed = buffer[out]; 
	out = (out + 1) % BUFFER_SIZE; 	
        counter--; 
	/* consume the item in next consumed */ 
} 


    return 0;
}