#include "serializer.h"


serializer::serializer()
{

}

serializer::~serializer()
{

}

void serializer::serializeTree(BST<Person*> &students, BST<Person*> &faculty)
{
    cout << "jere" << endl;

    ofstream tempStream;
    cout << "jere" << endl;

    tempStream.open("temp.txt");
    cout << "jere" << endl;

    serializeNode(students.root, tempStream);
    cout << "jere" << endl;

    tempStream << "---" << endl;
    cout << "jere" << endl;

    serializeNode(faculty.root, tempStream);
    cout << "jere" << endl;


    tempStream.close();
}

void serializer::serializeNode(TreeNode<Person*>* root, ofstream &myStream)
{
    if(root->left!=NULL) serializeNode(root->left, myStream);
    if(root!= NULL) root->value->save(myStream);
    if(root->right!=NULL) serializeNode(root->right, myStream);
}

void serializer::deserialize(BST<Person*> &students, BST<Person*> &faculty)
{
    ifstream in ("temp.txt");

    string s;
    int size = 6;
    string delimiter = "|";
    size_t pos = 0;
    string token[size];
    int count = 0;
    bool student = true;

    while(getline(in, s))
    {
        if (s == "---")
        {
            student = false;
            continue;
        }

        while ((pos = s.find(delimiter)) != string::npos)
        {
            token[count] = s.substr(0,pos);
            count++;
            s.erase(0,pos + delimiter.length());
        }
        if(student)
        {
            token[size - 1] = s;
            Person *p = new Student(parseInt(token[0]),   //ID
                                             token[1],    //Name
                                             token[2],    //Level
                                             token[3],    //Major
                                    parseInt(token[4]),   //Advisor
                                 parseDouble(token[5]));  //GPA

            students.insert(p->id, p);
        }
        else
        {
            token[size - 3] = s;
            Person *p = new Faculty(parseInt(token[0]),   //ID
                                             token[1],    //Name
                                             token[2],    //Level
                                             token[3]);  //department


            faculty.insert(p->id, p);

            // This needs to be put back later
        }
        pos = 0;
        count = 0;
    }
    in.close();
    reverseAssignAdvisees(students,faculty);

}

int serializer::parseInt(string s)
{
    return stoi(s);
}
double serializer::parseDouble(string s)
{
    return stod(s);
}
void serializer::reverseAssignAdvisees(BST<Person*> &students, BST<Person*> &faculty)
{
    recAdd(students.root, faculty);
}

void serializer::recAdd(TreeNode<Person*>* node, BST<Person*> &faculty)
{
    if(node == NULL) return;

    recAdd(node->left, faculty);
    Student *l = (Student*)node->value;
    searchAddAdvisee(l->advisorID, node->key, faculty);
    recAdd(node->right, faculty);

}
void serializer::searchAddAdvisee(int advisor, int advisee, BST<Person*> &faculty)
{
    if(faculty.contains(advisor))
    {
        TreeNode<Person*>* current = faculty.root;
        TreeNode<Person*>* parent = faculty.root;

        while(current->key != advisor)
        {
            parent = current;

            current = (advisor < current->key) ? current->left : current->right;
        }
        Faculty *l = (Faculty*)current->value;
        l->AddAdvisee(advisee);
    }
}
