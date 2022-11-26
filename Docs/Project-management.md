# **Hospital-management-system**  
## INTRODUCTION
A hospital management system, made using object-oriented programming and file handling in C++
<hr>

### **DESCRIPTION**
### **GOALS & OBJECTIVES**
<hr>

####  GOAL 1 :&nbsp; &nbsp;Add base class for adding people
<hr>

#### OBJECTIVES :

- Creating a base class `person` derive all another classes from it later;
- Functionality of class `person`
  - Add appropriate fields to store the basic details of a person;
  - Create abstract (virtual) method `addPerson` that take person details when registered;
  - Declare an abstract method `getDetails` to search for a registered person in the database;
  - Create an abstract method to print the basic details of a person;
  - Create a method to remove (un-register) a registered person;

<br>

####  GOAL 2 :&nbsp; &nbsp; Store address separately, in a structured manner
<hr>

#### OBJECTIVES :
- Create a class address containing private fields: string line1, line2, city, state, pinCode, country to store the address of a location;
- Create appropriate methods to take address as input from the user-side, encrypt (not-really convert it into another format) 
 it into a string to store it into a single cell of a CSV file, decrypt encrypted address string and output the address in a structured manner;
- Create an instance of class address in class person to store the address.