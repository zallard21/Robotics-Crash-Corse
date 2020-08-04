// Array Task 1

void setup() {
  Serial.begin(9600);

  // Creat an array of type int and size 10:
  int nums[10];
  // Using a while loop, fill the array with multiples of 3 between 3 and 30 (inclusive):
                // Remember the syntax?
                // while (condition) {
                //       code...
                // }
  int index = 0; 
  while(index<10) {
    nums[index]=(index+1)*3;
    index++;
  }


  // Rewrite the code above with a for loop:
                // Remember the syntax?
                // for (initialization; condition; update variable) {
                //       code...
                // }
  for(int i=0; i<10; i++) {
    nums[index]=(index+1)*3;
  }


  // Write a loop that will go through the array 
  //     and print any values that are a multiple of 9:
                // Hint: Use the % (modulus) operator.
  for(int i=0; i<10; i++) {
    if(nums[i]%9==0) {
      Serial.println(nums[i]);
    }
  }

  Serial.println(sizeof(nums)/sizeof(nums[0])); // length in c++

}

void loop() {
  // put your main code here, to run repeatedly:

}
