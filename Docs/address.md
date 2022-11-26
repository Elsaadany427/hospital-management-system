## **Class address:**

the class address is made to be able to perform the following tasks:

    take addresses as inputs,
    convert them to a string (of a specified format) and return the string to be saved in *.csv files &
    read the same strings to generate back the initially input address and output it.

### **Fields**:

the class address has the following fields as its private members;

    string m_line1, m_line2;
    string m_city;
    string m_state;
    string m_pinCode;
    string m_country;

### **Methods**:

the class address has the following methods as its public members;

    Address();
    void takeAddress();
    void printAddress();
    string encryptAddress();
    void decryptAddress(string);

### **Funtioning**:

    Address(); : the constructor of the class initializes all the fields of the class by an empty string i.e. "";

    void takeAddress(); : this function takes each of the fields (all are of type string) as input from the user side;

    void printAddress(); : this function outputs each of the fields in a structured manner;

    string encryptAddress(); : this function converts the address contained in the fields of address object that called this funtion into a string (of specified format) and returns it;

        values of the different fields i.e. line1, line2, city, state, pinCode, country are pushed into the address string seperated by a / character, since commas (,) are already used by csv files for differentiating adjacent cells of the same row;

        also, since values of the fields line1 and line2 might contain commas (,), so, before storing them, an iteration is performed over them and each , is replaced by ~;

```c++
std::stringstream sObj;
sObj << m_line1 << "/" << m_line2 << "/" << m_city << "/" << m_state << "/" << m_pinCode << "/" << m_country;
std::string encryptedAddress;
getline(sObj, encryptedAddress);
for (auto &i: encryptedAddress)
    if (i == ',')
        i = '~';
```


    decryptAddress(string); : takes the address string as the only argument and fills the fields of calling object (aka this) accordingly by reading the address string using getline(); function and an stringstream object;

        the / character is passed as the delimiter to the getline(); function and the fields are filled one by one;

        once all the fields are filled, an iteration is performed over the fields line1 and line2 and each ~ is replaced back by ,;

```c++
std::stringstream s(t_encryptedAddress);

getline(s, m_line1, '/');
for (auto &i: m_line1)
    if (i == '~')
        i = ',';

getline(s, m_line2, '/');
for (auto &i: m_line2)
    if (i == '~')
        i = ',';

getline(s, m_city, '/');
getline(s, m_state, '/');
getline(s, m_pinCode, '/');
getline(s, m_country, '/');
```