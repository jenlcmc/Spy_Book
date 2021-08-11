#include <iostream>
#include "spyBook.h"
#include "spyBookExc.h"
#include "searchList.h"
#include "menu.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

/**spyBook - constructor to set var to null and load file
     * string file name- to use for loadFile()
     * Algo - set all pointers to null and then call loadFile
    */
spyBook::spyBook(string filename) {
    head = NULL;
    last = NULL;
    firstToDisplay = NULL;
    loadFile(filename); //to populate linked list
    firstToDisplay = NULL; //extra test
}

/**~spyBook- destructor to set title
    * Algo - like what it say in the funct
    */
spyBook::~spyBook() {
    info* temp = NULL; 
    while(head != NULL){ //trasnverse
        temp = head; //temp = head
        head = head->next; //update head
        delete temp; //delete temp
    }
    last = NULL; //avoid dangling pointer
}

/**displayRecord - display the record in full form
     * record* r- element to display
     * return void
     * Algo - display the element by access it mem
    */
void spyBook::displayRecord(info *r) {
    cout  << "Name: " << r->first_name << " " << r->last_name << endl;
    cout <<  "Spy Agency/Occupation: " << r->spy_agency << endl;
    cout <<  "City: " << r->city << endl;
    cout <<  "State: " << r->state << endl;
    cout <<  "Born year: " << r->born_year << endl;
    cout <<  "Death Age: " << r->death_age << endl;;
    cout <<  "Notes: "  << r->notes << endl;
    cout << endl;
}

/**display3 - display 3 record
     * return void
     * Algo - like what it say in fuct
    */
void spyBook::display3() {
    //check to see if list is empty or not
    if(head == NULL){
        return;
    }
    //scroll == last case -> display 1 record
    if(last != NULL && firstToDisplay == last){
        displayRecord(firstToDisplay);
    }
    //chec kto see if the 2nd to last null or not
    //display 2 records
    else if(last != NULL && firstToDisplay == last->prev){
        displayRecord(firstToDisplay);
        displayRecord(firstToDisplay->next);
    }
    //check to see if next 2 nodes is null or not
    //display 3 records
    else if(firstToDisplay->next->next != NULL){
        displayRecord(firstToDisplay);
        displayRecord(firstToDisplay->next);
        displayRecord(firstToDisplay->next->next);
    }
    
}

/**displayAll - display all records
     * record *current - element to displat
     * Algo - check to see if list or node empty or not
     * if not, call displayRecord to display the elem
     * and recursive the funct again with current update
    */
void spyBook::displayAll(info *current) {
    if(head == NULL || current == NULL){
        return;
    }else{
        displayRecord(current);
        displayAll(current->next);
    }
}

/**displayTree - display in tree form
     * record *current - element to display
     * int indent- to \t depend on num of indent
     * Algo - check to see if list or node empty or not
     * if not, loop the indent to cout '\t'
     * then cout the compact form and update child depend on condition
     * if have child, indent + 1 else, indent = 0
     * last, recursive the funct with curr and indent update
    */
void spyBook::displayTree(info*current, int indent) {
    if(head == NULL || current == NULL){
        return;
    }else{
        for(int i = 0 ; i < indent; i ++){
            cout << '\t';
        }
        cout << "id= " << current->id << '\t' << "name= " << current->first_name << " " << current->last_name << endl;

        if(current->child != NULL){
            indent = indent + 1;
        }
        if(current->child == NULL){
            indent = 0;
        }
        
        displayTree(current->next, indent);
    }
}

/**display - display depend on choice
     * const char option- option to choice which one to display 
     * Algo - if 0- display all, if 1, display tree
    */
void spyBook::display(const char option) {// 0: all, full     1: tree
    int indent = 0;
    firstToDisplay = head;
    if(option == 0){
        displayAll(firstToDisplay); 
    }else if(option == 1){
        displayTree(firstToDisplay, indent);
    }else{
        return;
    }
}

/**goToFirst - go to first elem
     * return void
     * Algo - set firstToDisplay to head and call display3
    */
void spyBook::goToFirst() {
    firstToDisplay = head;
    display3();
}

/**operator++ - to move down one elem
     * Algo - if elem is last = do nothing
     * else, set 1st to display to next one and display3()
    */
void spyBook::operator++() {
    if(firstToDisplay == last){
        return;
    }
    else{
        firstToDisplay = firstToDisplay->next;
        display3();
    }
}

/**operator++ - to move up one elem
     * Algo - if elem is head = do nothing
     * else, set 1st to display to prev one and display3()
    */
void spyBook::operator--(){
    if(firstToDisplay == head){
        return;
    }
    else{
        firstToDisplay = firstToDisplay->prev;
        display3();
    }
}

/**parseAllocate - to parse and set value
    * string line- to parse string
     * Algo - description in the finct
    */
info* spyBook::parseAllocate(string line) { 
    int parentID = 0;
    info* afterParse = new info;
    info* curr = NULL;

    string delim = ","; //char use to parse
    vector<string> parse; //vec use to store parse 
	int begin = 0; //begin of the line 
    size_t fin = line.find(delim); //final of the line = stop when it find ','
    

    //clear for new record
    parse.clear();

    //loop to find and parse string using vec and find()
    //so this while loop will skip the last field
	while (fin != string::npos){ //loop until the end of the line is delim
    //use push back to push field into vec
    //substr - from the begin to the end-begin
		parse.push_back(line.substr(begin, fin - begin));
        //update begin by start from next field seperate by comma
        //update new end. find for ',' and from new begin position
        fin = line.find(delim,(begin = fin + delim.length()));
	}
    //this is for the last field / to add last field
	parse.push_back(line.substr(begin, fin - begin));
    
	//set value
    afterParse->id = stoi(parse[0]);
    afterParse->first_name = parse[2];
    afterParse->last_name = parse[3];
    afterParse->spy_agency = parse[4];
    afterParse->city = parse[5];
    afterParse->state = parse[6];
    afterParse->born_year = parse[7];
    afterParse->death_age = parse[8];
    afterParse->notes = parse[9];

    
    //special one/ parent id 
    parentID = stoi(parse[1]);
    curr = head; //use to transverse
    afterParse->child = NULL; //set null to prevent data overwrote/error
    
    if(parentID != 0){//condition to check to see if have parent ot not
        while(curr != NULL){//transverse the list
            if(curr->id == parentID){ //if find
                curr->child = afterParse; //address child will be address of the node
                break;
            }
            curr = curr->next; //update transverse
        }
    }
    return afterParse;
}

/**addRecord - add record
    * string line- to use it in parse()
     * Algo - description in the finct
    */
void spyBook::addRecord(string line) {
    info* temp;
    //this will aslo update child too
    temp = parseAllocate(line); //call parse to have new node
    temp->next = NULL; //set the next to null
    // 2. add element to the list
    if (head == NULL) {    // list is empty
        temp->prev=NULL;
        head = temp;
        last = temp;
    } else {    // list is not empty, add at the end
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}

/**loadFile - to load the file and check
    * string filename- file to open
     * Algo - use try/catch to check for file
     * if cant open, throw error and use what() to display error + rethrow it again
     * if can open, then use while loop to read to the end of file and use getline and addRecord()
    */
void spyBook::loadFile(string filename) {
    string line;

    try
    {
        ifstream infile;
        filename = "records.csv";
        infile.open(filename);

        if(!infile.is_open()){
            throw spyBookExc("error opening the file: " + filename + '\n' + "ABORT");
        }else{
            while(!infile.eof()){
                getline(infile, line);
                addRecord(line);
                line.clear();
            }
            infile.close();
        }
    }
    catch(spyBookExc &noFile)
    {
        cout << noFile.what() << endl;
        throw noFile;
    }
    
}

/**search() - to seearch element based on user's chocie
    * return void
     * Algo - use Menu construct and add function to create a menu
     * then use displayAndread for confirm user choice
     * use switch statement to choice from user's choice
     * For options 1-4, the search()function asks user to enter the keyword. 
     * Once the keyword is provided, the search()function creates an object of searchListclass, named searchListObj. T
     * hen, still inside of search()function –the address book entries are checked against the search criteria (one of 1-4) 
     * and matching records are added to the searchListObj, using searchListclass members. 
     * Finally, the search results (i.e. elements of the searchListObj) are displayed in the compact form.
    */
void spyBook::search() {
    Menu makeMenu("SEARCH MENU");
    makeMenu.add("First name", '1');
    makeMenu.add("Last name", '2');
    makeMenu.add("City ", '3');
    makeMenu.add("State/ Country", '4');
    makeMenu.add("Back to previous menu", 'q');

    char Userchoice; 
    searchList searchListObj;
    info* temp;
    string keyword;
    Userchoice = makeMenu.displayAndRead();

    switch(Userchoice)
    {
        //quit case
    case 'q':
        return;
        break;
    
    //1st name case
    case '1':
        cout << "Enter keyword/string: ";

        //clear + ignore and getline
        cin.clear();
        cin.ignore(100, '\n');
        getline(cin ,keyword);
        //search for the keyword in the list
        cout << "searching against the keyword: " << keyword << endl;
        for(temp = head; temp != NULL; temp = temp->next){
            if(keyword == temp->first_name){ //match
                searchListObj.add(temp); //use add to add the var
            }
        }
        searchListObj.display(); //and display
        
        break;

    //same with '1'
    //case last name
    case '2':
        cout << "Enter keyword/string: ";

        cin.clear();
        cin.ignore(100, '\n');
        getline(cin ,keyword);

        cout << "searching against the keyword: " << keyword << endl;
        for(temp = head; temp != NULL; temp = temp->next){
            if(keyword == temp->last_name){
                searchListObj.add(temp);
            }
        }
        searchListObj.display();
        break;

    //same with '1'
    //case city
    case '3':
        cout << "Enter keyword/string: ";

        cin.clear();
        cin.ignore(100, '\n');
        getline(cin ,keyword);

        cout << "searching against the keyword: " << keyword << endl;
        for(temp = head; temp != NULL; temp = temp->next){
            if(keyword == temp->city){
                searchListObj.add(temp);
            }
        }
        searchListObj.display();
        break;

    //same with '1'
    //case state
    case '4':
        cout << "Enter keyword/string: ";

        cin.clear();
        cin.ignore(100, '\n');
        getline(cin ,keyword);

        cout << "searching against the keyword: " << keyword << endl;
        for(temp = head; temp != NULL; temp = temp->next){
            if(keyword == temp->state){
                searchListObj.add(temp);
            }
        }
        searchListObj.display();
        break;

    default:
        break;
    }
    
}

void spyBook::add(){
    cout << "To add new information of the spy, please follow description" << endl;
    cout << "The new spy information will be add at the end of the file" << endl;
    cout << "Press Enter after each prompt to save the data" << endl;
    cout << "After adding new information, please close the program to update new version of database\n";

    int parent = 0;
    int child = 0;
    string first;
    string last;
    string agency;
    string city;
    string state_country;
    string born_year;
    string death_age;
    string notes;
    string line;
    char choice;

    ifstream file("records.csv");

    while(!file.eof()){
        getline(file, line);
        ++parent;
    }
    parent = parent + 1;

    while(!cin.fail()){
        cout << "Enter first name: ";
        cin >> first;
        cout << "Enter last name: ";
        cin >> last;
        cout << "Enter agency, you can either enter full name or abbreviation: ";
        cin >> agency;
        cout << "Enter city: ";
        cin >> city;
        cout << "Enter state_country, you can either enter full name or abbreviation: ";
        cin >> state_country;
        cout << "Enter born_year: ";
        cin >> born_year;
        cout << "Enter death_age: ";
        cin >> death_age;
        cout << "Enter notes. Add anything you want about the spy: ";
        cin >> notes;
        cout << "To stop, enter q. Otherwise, enter other key" << endl;
        cin >> choice;


        string full = to_string(parent) + "," + to_string(child) + "," + first + "," + last + "," + agency
                + "," + city + "," + state_country + "," + born_year + "," + death_age + "," + notes;

        ofstream datafile;

        datafile.open("records.csv", std::ios_base::app);
        datafile << '\n' << full;

        ++parent;
        if(tolower(choice) == 'q'){
            break;
        }
    }
}
