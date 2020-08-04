// Circle Class
class Circle {
   // Private variables that can only be accessed within the class
   // Place private variables here.
   double radius;
  // Everything after "public" can be accesed outside of the class (i.e in "setup" or "loop")
  public:
    // Put a constructor here: What information is needed?
    Circle(double);

    // Create a function that returns area (use 3.14 for pi)
    double area();
    
    // Create a function that allows the user to update the values
    void setRadius(double);
    
};

// Definitions of functions declared above
Circle::Circle(double r) {
  radius = r;
}

double Circle::area() {
  return(3.14*radius*radius);
}

void Circle::setRadius(double r) {
  radius = r;
}

void setup() {
  // Instantiates the Circle class
  Circle thiccBoi(4.0);
  
  // Can only print after serial.begin()
  Serial.begin(9600);
  
  // Calls the area() function within the class
  double area = thiccBoi.area();
  
  // Prints area
  Serial.println(area);
  
  // Updates values
  thiccBoi.setRadius(5.0);
  
  // Prints new areas
  area = thiccBoi.area();
  Serial.println(area);
}

void loop() {
  // put your main code here, to run repeatedly:
}
