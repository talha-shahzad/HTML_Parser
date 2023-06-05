//*******************************************************************************************************
// *  Talha Shahzad
// *  21i-0540
// *  C
// *  Assignment 2
//********************************************************************************************************




#include<opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>



#include <iostream>
#include<fstream>

using namespace std;
using namespace cv;

int image_extractor(string path);
void LRU(int val);


// -----------------------> Queue class implementation <-----------------------------
struct node {

    int data;
    node* next;
    

};
class queue
{
public:
    node* head;
    node* tail;

    int Hit;
    int Fault;
    queue()
    {
        head = tail = NULL;
        Hit = Fault = 0;
    }
    void enque(int val)
    {
       // cout << val << " const " << val2 << endl;
        node* temp = new node;
        temp->data = val;
       
        temp->next = NULL;


        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;

        }
    }

    void enqued(int val)
    {
        node* temp = new node;
        temp->data = val;
        temp->next = NULL;

       node *p = search(val);
       
        if (head == NULL && tail == NULL)
        {
            head = temp;
            tail = temp;
            Fault ++ ;
        }
        else
        {
            if (search(val))
            {
               
                Hit++;
                if (sort(p))
                {
                    tail->next = temp;
                    tail = temp;
                     }
           
                
            }
            else
            {
                if (size() == 4)
                {
                    deque();
                }
                tail->next = temp;
                tail = temp;
                Fault++;
              
            }

        }
    }

    bool IsEmpty()
    {
        if (head == NULL && tail == NULL)
        {
            return 1;
        }
        else
            return 0;
    }

    node* search(int val)
    {
       
        node* p = head;
        while (p != NULL)
        {
            if (p->data == val)
            {
              
                return p;
           }
            else
            p = p->next;
        }
        return 0;
    }

    int size()
    {
        int d= 0;
        node* p = head;
        while (p!=NULL)
        {
            d++;
            p = p->next;
        }
        return d;
    }

 

    int deque()
    {
        node* temp = head;
        int d = head->data;
        if (head != tail)
            head = head->next;
        else
            head =tail= NULL;
        
        temp = NULL;
     
        return d;

    }



   bool sort(node* now)
    {
        node* p = head;
        bool f = 0;
      
        if (now==head)
        {
            deque();
            f = true;
       }
        else if(now!=tail)
        {
            while (p->next != now)
            {
                p = p->next;
            }
           p->next = now->next;

            now->next = NULL;
            f = true;
        }
        else
        {
            f = false;
        }

        return f;
    }

  
    void display()
    {
        node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
queue lru;

// -----------------------> stack class implementation <-----------------------------


template<class T>
struct Noode
{
    T data;
    Noode<T>* next;

};

template<class D>
class stack
{
public:
    Noode<D>* top;

    stack()
    {
        top = NULL;
    }
    void push(D val)
    {
        Noode<D>* temp = new Noode<D>;
        temp->data = val;
        temp->next = NULL;

     
        if (top == NULL)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }

    }
    D pop()
    {
        Noode<D>* temp = top;
        
            D d = top->data;           
            top = top->next;

            temp = NULL;
        delete temp;
        return d;
    }
    void display()
    {
        Noode<D>* temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool Isempty()
    {
        if (top == NULL)
        {
            return 1;
        }
        else
            return 0;
    }

    bool precedence_checker(char a, char b)
    {
        if (b == '+' || b == '-')
        {
            if (a == '+' || a == '-')
            {
                return 1;
            }
            else if (a == '*' || a == '/' || a == '%' || a == '^' || a=='&'|| a=='$')
            {
                return 1;
            }
            else if (a == '(')
            {
                return 0;
            }
            else if (a == ')')
            {
                return 0;
            }

        }
        else if (b == '*' || b == '/' || b == '%' )
        {
            if (a == '+' || a == '-')
            {
                return 0;
            }
            else if (a == '*' || a == '/' || a == '%')
            {
                return 1;
            }
            else if (a == '^' || a=='&' || a == '$')
            {
                return 1;
            }
            else if (a == '(')
            {
                return 0;
            }
            else if (a == ')')
            {
                return 0;
            }

        }
        else if (b == '(')
        {
            return 0;

        }
        else if (b == '^' || b=='&' || b == '$')
        {
            if (a == '+' || a == '-')
            {
                return 0;
            }
            else if (a == '*' || a == '/' || a == '%')
            {
                return 0;
            }
            else if (a == '^' || a == '$' || a=='&')
            {
                return 1;
            }
            else if (a == '(')
            {
                return 0;
            }
            else if (a == ')')
            {
                return 0;
            }
        }

    }

   D* postfix(string s)
    {
       
       bool signal = 0;
        int mover = 0;

       int space = false;
        bool other = false;

        D* ret = new D[s.length() + 1];
      
      

        if (!(s[1] >= 33 && s[1] <= 48) || s[1] == '^' || s[1] == '&' || s[1] == '$')
        {
            for (int i = 0; s[i] != '\0'; i++)
            {

                if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57)
                {
                    ret[mover] = s[i];
                    mover++;
                 
                    if (s[i] !='\0' && s[i + 1] != '\0' && s[i + 2] != '\0')
                    {
                      

                        if (s[i + 1] == 32 && (s[i + 2] >= 65 && s[i + 2] <= 90 || s[i + 2] >= 97 && s[i + 2] <= 122 || s[i + 2] >= 48 && s[i + 2] <= 57))
                        {
                            cout << "HELLO WORLD" << endl;
                            cout << s[i] << s[i + 1] << " " << s[i + 2] << endl;
                            signal = 1;
                        }

                    }
                }

                else if (s[i] >= 33 && s[i] <= 47 || s[i] == '^' || s[i]=='&' || s[i]=='$')
                {
                   

                    while (!Isempty() && precedence_checker(top->data, s[i]) && s[i] != ')')
                    {
                        if (precedence_checker(top->data, s[i]) == 1)
                        {
                            ret[mover] = pop();
                            mover++;
                        }
                        else
                        {

                            i++;
                        }

                    }

                    if (s[i] != ')')
                    {
                        push(s[i]);

                    }

                    if (s[i] == ')')
                    {

                        while (top->data != '(')
                        {

                            if (top == NULL)
                            {
                                signal= 1;
                                break;
                            }
                            ret[mover] = pop();
                            mover++;
                            if (top == NULL)
                            {
                                signal= 1;
                                break;
                            }


                        }
                        if (signal != 1)
                            pop();


                    }
                }



            }
        }
        else
        {
            signal = 1;
        }

        if (signal != 1)
        {
            while (!Isempty())
            {
                ret[mover] = pop();
                mover++;
            }
            ret[mover] = '\0';
            cout << ret << endl;
        }
        else
        {
            string str = "Invalid Expression";
            ret = new char[str.length()+1];
            for (int i = 0; i < str.length(); i++)
            {
                ret[i] = str[i];
            }
            ret[str.length()] = '\0';
            cout << ret << endl;
        }
      
      
        return ret;
        
    }


    D* prefix(string s)
    {
        string str = s;
        int mov = s.length() - 1;
        for (int i = 0; i < s.length(); i++)
        {
            str[i] = s[mov];
            mov--;
        }
        D* ret = new D[s.length() + 1];
        for (int i = 0; i < str.length(); i++)
        {
            ret[i] = str[i];

        }
        ret[s.length()] = '\0';
        for (int i = 0; i < s.length(); i++)
        {

            if (ret[i] == '(')
            {
                ret[i] = ')';
            }
            else if (ret[i] == ')')
            {
                ret[i] = '(';
            }

        }
        cout << ret << endl;
        bool weq = 0;
        ret = postfix(ret);
        string check = "Invalid Expression\0";

        for (int i = 0; i < check.length(); i++)
        {
            if (ret[i] == check[i])
            {
                weq = 1;
            }
            else
            {
                weq = 0;
                break;
            }
        }

        mov = 0;
        for (int i = 0; ret[i] != '\0'; i++)
        {
            mov++;
        }

        if (weq==0)
        {
            D* pre = new D[mov + 1];
            int r = mov - 1;
            for (int i = 0; i < mov; i++)
            {
                pre[i] = ret[r];
                r--;
            }
            pre[mov] = '\0';
            cout << pre << endl;
            return pre;
        }
        else
            return ret;

    }

   D post_solution(string s)
    {
        string str = s;
       bool mov = 0;
       int incr = 0;
       int why = 0;




        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == ')' || s[i] == '(')
            {
                mov = 1;
            }
        }
       
        if (mov == 0)
        {


            for (int i = 0; s[i] != '\0'; i++)
            {

                if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57 || s[i] == ' ')
                {
                    if (s[i] != ' ')
                    {
                        string nyt = " ";
                        nyt = s[i];
                        cout << nyt << endl;
                        push(nyt);



                    }
                }
                else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '&')
                {

                    if ((s[i] == '-') && (s[i + 1] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] >= 48 || s[i] <= 57) && (s[i + 1] != ' '))
                    {
                        string l = " ";
                        string l2 = " ";
                        l = s[i];
                        l2 = s[i + 1];
                        string d = l + l2;
                        cout << " " << l << " " << l2 << endl;
                        push(d);
                        i++;
                    }
                    else
                    {
                        string a1, a2;

                        if (!Isempty())
                            a2 = pop();

                        if (!Isempty())
                            a1 = pop();
                        char o = s[i];
                        string d = '(' + a1 + o + a2 + ')';
                        cout << d << endl;
                        push(d);
                    }
                }
            }
        }
               if (mov==1)
                 {
                     string t = "Invalid Expression\0";

                     push(t);
                  
                 }
              


      
             
        return top->data;
    }


};


//---------------------------------------------->>>>  START OF QUESTION 1 AND qUESTION 2 <<<<---------------------------------------------------------------


string priority(string s)
{
    int d = 0;
    int temp = 0;
    string dret= "  ";
    int mov = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            d = d * 10;
            temp = s[i] - 48;
            d = d + temp;
            dret[mov] = s[i];
            mov++;
        }

  }
    cout <<d << endl;
   LRU(d);

    return dret;
}
string paragraph(string s)
{

    string d = "  ";

    d = "\n";
    return d;

}
string headfun(string s)
{
    string d="    ";
    d[0] = '\t';
    d[1] = '\t';
    d[2] = '\t';
    d += s + "\n";
    return d;
}

string source(string s)
{
    cout << s << endl;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            s[i] = s[i + 1];
            i++;
          

        }
    }
    cout << s << endl;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '\\')
        {
            s[i] = '/';
        }
    }

    string r = ".png";
    string pathimg = "E:/UNIVERSITY/Data Structure/Assignment2/Assignment2";
    pathimg += s + r;
    cout << pathimg << endl;
    int ret = 0;
    string d = "  ";
    ret=image_extractor(pathimg);
    cout << "image opened" << endl;
    d[0] = ' ';
    d[1] = static_cast<char>(ret) + 48;
    return d;

}
string pickfun(string s)
{
    string d;
    d += s;
    return d;
}
string tickfun(string s)
{
    string d;
    d +=  s;
    return d;
}
string hickfun(string s)
{
    string d;
    d +=  s;
    return d;
}
string chkfun(string s)
{
    string d;
    d += s;
    return d;
}
string tabfun()
{
    string d="\t";
    return d;
}

void comparing(string tag, string str)
{
    stack<char> ps;
    stack<string> postsol;

    string pri = "|priorty|";
    string post = "|post_exp|";
    string para = "|paragraph|";
    string pre = "|pre_exp|";
    string In = "|In_exp|";
    string sol = "|sol_exp|";
    string sor = "|src|";
    string pick = "|pick|";
    string chk = "|chk|";
    string hick = "|hick|";
    string tick = "|tick|";
    string head = "|head|";
    string tab = "|tab|";
    string start = "|start|";

    bool f = true;

    cout << "coming tags :----------------->" << tag << endl;;
    cout << " word to do oon :------------------->" << str << endl;

    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == tab[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);


        MyFile << tabfun();

        MyFile.close();
       

    }

    f = true;

    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == start[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);


        MyFile << "\n";
        MyFile.close();
      

    }

    f = true;

    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == pri[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }


    if (f == true)
    {
      
     
    priority(str);

     
      
    }

    f = true;

    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == post[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << ps.postfix(str);

        MyFile.close();
     
    }

    f = true;

    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == In[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << ps.postfix(str);

        MyFile.close();

    }

    f = true;


    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == pre[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }

    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << ps.prefix(str);

        MyFile.close();
      
    }

    f = true;
    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == para[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }


    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

      
        MyFile << paragraph(str);

        MyFile.close();
        
    }

    f = true;

    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == sol[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }

    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << postsol.post_solution(str);

        MyFile.close();
      
    }

    f = true;
    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == hick[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << hickfun(str);

        MyFile.close();

    }


    f = true;
    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == pick[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }

    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << pickfun(str);

        MyFile.close();

    }
    f = true;
    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == tick[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << tickfun(str);

        MyFile.close();

    }
    f = true;
    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == chk[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }

    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << " ";
        MyFile << chkfun(str);

        MyFile.close();

    }

    f = true;
    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == sor[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }

    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << source(str);

        MyFile.close();


    }

    f = true;

    for (int i = 0; i < tag.length(); i++)
    {
        if (tag[i] == head[i])
        {
            f = true;
        }
        else
        {
            f = false;
            break;
        }
    }
    if (f == true)
    {
        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << headfun(str);

        MyFile.close();
       

    }
    f = true;



}
bool equal_checker(string nw,string stak)
{
    bool f = false;;
    bool misend = 0;

    cout << "new one is : " << nw << endl;
    cout << "in stack is : " << stak << endl;


   


    if (misend == 0)

    {
        for (int i = 0; nw[i] != '\0'; i++)
        {
            if (i == 0)
            {
                if (nw[i] == stak[i])

                {
                    cout << nw[i] << endl;
                    f = true;
                }
                else
                {
                    cout << nw[i] << endl;
                    f = false;
                    break;
                }
            }
            if (i == 1 && nw[1] == '\\')
            {
                cout << nw[i] << endl;
                f = true;
            }
            if (i > 1)
            {
                cout << nw[i] << endl;
                if (nw[i] == stak[i - 1])

                {
                    cout << nw[i] << endl;
                    f = true;
                }
                else
                {
                    cout << nw[i] << endl;
                    f = false;
                    break;
                }
            }

        }
    }
   
    if (f== 0)
    {
        string d = "Error due to this ending tag : ";

        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        d += "\n" + nw + "\n";

        MyFile << d;

        MyFile.close();

    }

    return f;

}
void parsing(string filename)
{
    stack<string> st;
      
    bool dotchecker = false;
    int counter = 0;


        fstream file;
        string word;
        string sending;
        string diversion;

     

        
        file.open(filename);

        while (file >> word)
        {
          
        


            if (word[0] == '|' && word[1] != '\\')
            {
              

                ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

                MyFile << sending;
             
                MyFile.close();
               

                for (int i = 0; word[i] != '\0'; i++)
                {
                    if (word[i] == '.')
                    {
                        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

                        MyFile << "\n";

                        MyFile.close();

                        word[i] = '\0';
                    }
                }
              
              
                st.push(word);

                sending = "";
               
               

            }
            else if (word[0] >= 65 && word[0] <= 90 || word[0] >= 97 && word[0] <= 122 || word[0] >= 48 && word[0] <= 57 || word[0] >= 33 && word[0] <= 46 || word[0]==':' || word[0]=='\"' || word[0]=='*' || word[0]=='/' || word[0]=='&' || word[0]=='$' || word[0]=='^' || word[0]=='\\')
            {

                sending += ' '+  word;
                    
            }
            else if (word[0] == '|' && word[1] == '\\')
            {
               
               
                for (int i = 0; word[i] != '\0'; i++)
                {
                    if (word[i] == '.')
                    {
                        if (word[i] == '.')
                        {
                            word[i] = '\0';
                            dotchecker = true;
                        }
                       
                    }
                }

              

                bool sender = false;
               sender= equal_checker(word,st.top->data);
               if (sender == true)
               {
                   comparing(st.top->data, sending);
                  st. pop();

               }
              

               sending = "";

            }
            if (dotchecker == true)
            {
                ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

                MyFile << ".";
                MyFile << "\n";

                MyFile.close();
                dotchecker = false;
            }
        
         


        }    
    
        while (!st.Isempty())
        {
            cout << st.top->data << endl;

            ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

            MyFile << "\n";

            MyFile << " Syntax Error Stack not empty error due to given tag : ";
            MyFile <<  st.top->data;
            MyFile << "\n";

            MyFile.close();

            st.pop();

        }

     
}




template <typename T>
void display(T** image_array, int rows, int cols, Mat image, string path)
{
    Mat ima = imread(path);
    ima.rows = rows;
    ima.cols = cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ima.at<Vec3b>(i, j)[2] = image_array[i][j];
            ima.at<Vec3b>(i, j)[1] = image_array[i][j];
            ima.at<Vec3b>(i, j)[0] = image_array[i][j];
        }
    }
    imshow("Window01.bmp", image);
    imshow("Window02.bmp", ima);
    waitKey(0);
}




//---------------------->>>>   THIS COMMENTED CODE IS OF QUESTION 4 AND IS DONE WITH THE HELP OF QUESTION 1 OF ASSIGNMENT 1  <<<<<<<<------------------------------------------------




//
//float** Question4()
//{
//
//
//    Mat img = imread("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Images/Img2.png");   // for Question 1
//
//
//    int imgrows = img.rows;
//    int  imgcols = img.cols;
//
//    float** a = new float* [img.rows];
//    for (int i = 0; i < img.rows; i++)
//    {
//        a[i] = new float[img.cols];
//    }
//
//    for (int i = 0; i < img.rows; i++)
//    {
//        for (int j = 0; j < img.cols; j++)
//        {
//            a[i][j] = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
//        }
//
//    }
//
//    int* label = new int[2000];
//    int count = 0;
//
//    for (int i = 0; i < 2000; i++)
//    {
//        label[i] = i + 1;
//    }
//
//
//
//    // labelling starts from here
//
//
//    for (int i = 0; i < imgrows; i++)
//    {
//        for (int j = 0; j < imgcols; j++)
//        {
//
//            // for first row
//            if (i == 0)
//            {
//                if (a[i][j] == 255 && a[i][j - 1] == 0)
//                {
//                    a[i][j] = label[count];
//                    count++;
//                }
//
//                else
//                {
//                    for (int m = 0; m <= count; m++)
//                    {
//                        if (a[i][j] == 255 && a[i][j - 1] == label[m])
//                        {
//                            a[i][j] = label[m];
//                            break;
//                        }
//                    }
//                }
//            }
//
//
//
//            // for first column
//
//            if (j == 0)
//            {
//                // for first entry if it is 255 by chance then do noting 
//                if (i == 0)
//                {
//                    if (a[i][j] == 0)
//                    {
//                        a[i][j] = 0;
//                    }
//                    else
//                    {
//                        a[i][j] = label[count];
//                        count++;
//                    }
//                }
//                // for other element in that same column
//                else
//                {
//                    if ((a[i][j] == 255) && (a[i - 1][j] == 0 && a[i - 1][j + 1] == 0))
//                    {
//                        a[i][j] = label[count];
//                        count++;
//
//                    }
//
//                    else
//                    {
//                        for (int m = 0; m <= count; m++)
//                        {
//                            if ((a[i][j] == 255) && (a[i - 1][j] == label[m] || a[i - 1][j + 1] == label[m]))
//                            {
//
//                                a[i][j] = label[m];
//
//                                a[i][j] = label[m];
//                                if (a[i - 1][j] != 0 && a[i - 1][j] != label[m])
//                                {
//                                    for (int s = i; s >= 0; s--)
//                                    {
//                                        for (int e = j; e >= 0; e--)
//                                        {
//                                            if (a[s][e] == a[i - 1][j])
//                                                a[s][e] = label[m];
//                                        }
//                                    }
//
//                                }
//
//                                if (a[i - 1][j + 1] != 0 && a[i - 1][j + 1] != label[m])
//                                {
//                                    for (int s = i; s >= 0; s--)
//                                    {
//                                        for (int e = j; e >= 0; e--)
//                                        {
//                                            if (a[s][e] == a[i - 1][j + 1])
//                                                a[s][e] = label[m];
//                                        }
//                                    }
//
//                                }
//
//                                break;
//                            }
//                        }
//                    }
//
//
//
//                }
//            }
//
//            // f0r last column
//
//            if (j == imgcols - 1)
//            {
//                // for last element of first row 
//
//                if (i == 0)
//                {
//                    if (a[i][j] == 255 && a[i][j - 1] == 0)
//                    {
//                        a[i][j] = label[count];
//                        count++;
//                    }
//
//                    else
//                    {
//                        for (int m = 0; m <= count; m++)
//                        {
//                            if (a[i][j] == 255 && a[i][j - 1] == label[m])
//                            {
//                                a[i][j] = label[m];
//
//
//
//
//                                break;
//                            }
//                        }
//                    }
//
//
//
//                }
//                // for other elements of last column other then row one
//                else
//                {
//                    if ((a[i][j] == 255) && (a[i - 1][j] == 0 && a[i - 1][j - 1] == 0 && a[i][j - 1] == 0))
//                    {
//                        a[i][j] = label[count];
//                        count++;
//
//                    }
//                    else {
//                        for (int m = 0; m <= count; m++)
//                        {
//                            if ((a[i][j] == 255) && (a[i - 1][j] == label[m] || a[i - 1][j - 1] == label[m] || a[i][j - 1] == label[m]))
//                            {
//                                a[i][j] = label[m];
//
//
//                                if (a[i - 1][j] != 0 && a[i - 1][j] != label[m])
//                                {
//                                    for (int s = i; s >= 0; s--)
//                                    {
//                                        for (int e = j; e >= 0; e--)
//                                        {
//                                            if (a[s][e] == a[i - 1][j])
//                                                a[s][e] = label[m];
//                                        }
//                                    }
//
//                                }
//
//                                if (a[i - 1][j - 1] != 0 && a[i - 1][j - 1] != label[m])
//                                {
//                                    for (int s = i; s >= 0; s--)
//                                    {
//                                        for (int e = j; e >= 0; e--)
//                                        {
//                                            if (a[s][e] == a[i - 1][j - 1])
//                                                a[s][e] = label[m];
//                                        }
//                                    }
//
//                                }
//
//                                if (a[i][j - 1] != 0 && a[i][j - 1] != label[m])
//                                {
//                                    for (int s = i; s >= 0; s--)
//                                    {
//                                        for (int e = j; e >= 0; e--)
//                                        {
//                                            if (a[s][e] == a[i][j - 1])
//                                                a[s][e] = label[m];
//                                        }
//                                    }
//
//                                }
//
//
//                                break;
//                            }
//                        }
//                    }
//
//
//
//                }
//            }
//
//            // for all remaining elements in array
//            if (i > 0 && j < imgcols - 1 && i < imgrows && j>0)
//            {
//                if ((a[i][j] == 255) && (a[i - 1][j] == 0 && a[i - 1][j + 1] == 0 && a[i - 1][j - 1] == 0 && a[i][j - 1] == 0))
//                {
//                    a[i][j] = label[count];
//                    count++;
//
//                }
//                else {
//                    for (int m = 0; m <= count; m++)
//                    {
//                        if ((a[i][j] == 255) && (a[i - 1][j] == label[m] || a[i - 1][j + 1] == label[m] || a[i - 1][j - 1] == label[m] || a[i][j - 1] == label[m]))
//                        {
//                            a[i][j] = label[m];
//
//
//                            if (a[i - 1][j] != 0 && a[i - 1][j] != label[m])
//                            {
//                                for (int s = i; s >= 0; s--)
//                                {
//                                    for (int e = j; e >= 0; e--)
//                                    {
//                                        if (a[s][e] == a[i - 1][j])
//                                            a[s][e] = label[m];
//                                    }
//                                }
//
//                            }
//
//
//                            if (a[i - 1][j + 1] != 0 && a[i - 1][j + 1] != label[m])
//                            {
//                                for (int s = i; s >= 0; s--)
//                                {
//                                    for (int e = j; e >= 0; e--)
//                                    {
//                                        if (a[s][e] == a[i - 1][j + 1])
//                                            a[s][e] = label[m];
//                                    }
//                                }
//
//                            }
//
//
//
//                            if (a[i - 1][j - 1] != 0 && a[i - 1][j - 1] != label[m])
//                            {
//                                for (int s = i; s >= 0; s--)
//                                {
//                                    for (int e = j; e >= 0; e--)
//                                    {
//                                        if (a[s][e] == a[i - 1][j - 1])
//                                            a[s][e] = label[m];
//                                    }
//                                }
//
//                            }
//
//                            if (a[i][j - 1] != 0 && a[i][j - 1] != label[m])
//                            {
//                                for (int s = i; s >= 0; s--)
//                                {
//                                    for (int e = j; e >= 0; e--)
//                                    {
//                                        if (a[s][e] == a[i][j - 1])
//                                            a[s][e] = label[m];
//                                    }
//                                }
//
//                            }
//
//
//                            break;
//                        }
//                    }
//                }
//
//            }
//
//
//
//        }
//    }
//
//
//
//
//    int multiplicity[2000] = { 0 };
//
//    for (int k = 0; k < 2000; k++)
//    {
//
//        for (int i = 0; i < imgrows; i++)
//        {
//            for (int j = 0; j < imgcols; j++)
//            {
//                if (a[i][j] == label[k])
//                {
//                    ++multiplicity[k];
//                }
//            }
//        }
//    }
//
//    int arrcount = 0;
//    int indexcat[6] = { 0 };
//    for (int i = 0; i < 1000; i++)
//    {
//        if (multiplicity[i] > 5000)
//        {
//            indexcat[arrcount] = i;
//
//            arrcount++;
//        }
//    }
//
//
//    float*** arr = new float** [arrcount];
//
//    for (int k = 0; k < arrcount; k++)
//    {
//        arr[k] = new float* [imgrows];
//
//        for (int i = 0; i < imgrows; i++)
//        {
//            arr[k][i] = new float[imgcols];
//        }
//
//
//    }
//    for (int ik = 0; ik < arrcount; ik++)
//    {
//
//        for (int i = 0; i < imgrows; i++)
//        {
//            for (int j = 0; j < imgcols; j++)
//            {
//                if (a[i][j] == indexcat[ik] + 1)
//                {
//
//                    arr[ik][i][j] = 1;
//                }
//                else
//                {
//                    arr[ik][i][j] = 0;
//                }
//
//            }
//        }
//    }
//
//    for (int k = 0; k < arrcount; k++)
//    {
//        for (int i = 0; i < imgrows; i++)
//        {
//            for (int j = 0; j < imgcols; j++)
//            {
//                if (arr[k][i][j] != 0)
//                {
//                    arr[k][i][j] = 255;
//                }
//            }
//        }
//    }
//
//
//    Mat ima = imread("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Images/Img2.png");
//
//
//    for (int k = 0; k < arrcount; k++)
//    {
//        display(arr[k], img.rows, img.cols, img, "E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Images/Img2.png");
//
//
//        for (int i = 0; i < imgrows; i++)
//        {
//            for (int j = 0; j < imgcols; j++)
//            {
//                ima.at<Vec3b>(i, j)[2] = arr[k][i][j];
//                ima.at<Vec3b>(i, j)[1] = arr[k][i][j];
//                ima.at<Vec3b>(i, j)[0] = arr[k][i][j];
//            }
//        }
//
//        string r = "E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Images/        ";
//        string sara = "img2_2.png";
//        sara[5] = k + 48;
//        r = r + sara;
//        imwrite(r, ima);
//
//    }
//    return (arr[1]);
//
//}

//---------------------------------------------->>>> QUESTION 4 <<<<---------------------------------------------------------------

int image_extractor(string path)
{

    queue obj;
    queue obj2;
 
    Mat img = imread(path);

    float** a = new float* [img.rows];

    for (int i = 0; i < img.rows; i++)
    {
        a[i] = new float[img.cols];
    }


    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            a[i][j] = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
        }

    }

    float** checkingin = new float* [img.rows];

    for (int i = 0; i < img.rows; i++)
    {
        checkingin[i] = new float[img.cols] {0};
    }


    int k = 0;

    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {

            if (a[i][j] == 255)
            {
                obj.enque(i);
                obj2.enque(j);
         


                 while (!(obj.IsEmpty()) && !(obj2.IsEmpty()))//  while(!(s1.Isempty()) && !(s2.Isempty()))
                {
                    
                     int d1 = obj.deque();
                    int d2 = obj2.deque();

           
                    a[d1][d2] = 0;
                    //  cout << "-------------------------------------------------++++++++++++> " << d1 << " " << d2 << endl;
                   checkingin[d1][d2] = 255;
                    
                 

                    if (a[d1][d2 + 1] == 255)
                    {
                        
                        obj.enque(d1);
                        obj2.enque(d2 + 1);
                    
                        a[d1][d2 + 1] = 0;
                       
                    }
                  

                    if (a[d1][d2 - 1] == 255)
                    {
                        
                        obj.enque(d1);
                        obj2.enque( d2 - 1);
                    
                        a[d1][d2 - 1] = 0;
                       
                    }
                   
                    if (a[d1 + 1][d2 + 1] == 255)
                    {
                       
                        obj.enque(d1 + 1);
                        obj2.enque( d2 + 1);
                 
                        a[d1 + 1][d2 + 1] = 0;
                      
                    }
                   
                    if (a[d1 + 1][d2] == 255)
                    {
                       
                        obj.enque(d1 + 1);
                        obj2.enque( d2 );
                 
                        a[d1 + 1][d2] = 0;
                      
                    }
                   
                    if (a[d1 + 1][d2 - 1] == 255)
                    {
                       
                        obj.enque(d1 + 1);
                        obj2.enque(d2 - 1);
                 
                        a[d1 + 1][d2 - 1] = 0;
                       
                    }
                   
                    if (a[d1 - 1][d2 + 1] == 255)
                    {
                       
                       obj.enque(d1 - 1);
                       obj2.enque(d2 + 1);
             
                        a[d1 - 1][d2 + 1] = 0;
                      
                    }
                  

                    if (a[d1 - 1][d2 - 1] == 255)
                    {
                        
                       obj.enque(d1 - 1);
                       obj2.enque(d2 - 1);
                
                        a[d1 - 1][d2 - 1] = 0;
                      
                    }
                 
                  

                    if (a[d1 - 1][d2] == 255)
                    {
                        
                        obj.enque(d1 - 1);
                        obj2.enque(d2 );
            
                        a[d1 - 1][d2] = 0;
                      
                    }
                  
                }



                display(checkingin, img.rows, img.cols, img, path);
                Mat imd = imread(path);

                for (int i = 0; i < img.rows; i++)
                {
                    for (int j = 0; j < img.cols; j++)
                    {
                        imd.at<Vec3b>(i, j)[2] = checkingin[i][j];
                        imd.at<Vec3b>(i, j)[1] = checkingin[i][j];
                        imd.at<Vec3b>(i, j)[0] = checkingin[i][j];
                    }
                }

                string r = "E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Images/        ";
                string sara = "img2_2.png";

               
                sara[3] = path[path.length()-5];
                sara[5] = k + 48;
                r = r + sara;
                imwrite(r, imd);

                k++;


                for (int i = 0; i < img.rows; i++)
                {
                    for (int j = 0; j < img.cols; j++)
                    {
                        checkingin[i][j] = 0;
                    }
                }

            }
     
 
        }
           
    }
    cout <<" total galaxies :       " << k << endl;
    return k;

}


//---------------------------------------------->>>> QUESTION 3 <<<<---------------------------------------------------------------

void LRU(int val)
{
    int d= lru.size();
    


    if (d < 4)
    {
        lru.enqued(val); 
        lru.display();
    }
    else
    {
     
        lru.enqued(val);
        lru.display();

    }
}


int main()
{
    
    //------------------> Question number 1 just change the file name at end to parse that file

   // parsing("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Test_files/Test-7.txt");


    //--------------------->Question number 3

    string path = "E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Test_files/Test-7.txt";
    char c='y';
    int number = 0;
    while (c=='y' || c=='Y')
    {
        cout << "enter file you want to run" << endl;
        cin>>number;

        path[path.length() - 5] = number + 48;

        cout << path << endl;

        parsing(path);

        ofstream MyFile("E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Output_files/answer.txt", ios::app);

        MyFile << "\n";

        string j = " "; j[0] = (lru.Fault + 48);
        string l = " "; l[0] = (lru.Hit + 48);
        string t = "fault : " + j + "\t"+ "Hit : " + l;
        MyFile << t ;
      
        cout << t << endl;
        MyFile << "\n";

        MyFile.close();


        cout << "enter you want to continue" << endl;
        cin >> c;
   }
  

     // -------------------> Question umber 4 
   /* string pathimg = "E:/UNIVERSITY/Data Structure/Assignment2/Assignment2/Images/Img1.png";
    image_extractor(pathimg);*/



    //--------------------->  question done with the help of question 1 of assignment 1
    //Question4();  
}