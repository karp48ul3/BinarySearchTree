#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <map>

#define screenWidth 40

using namespace std;

struct node {
int key;
struct node *leftChild;
struct node *rightChild;
list<node>::iterator position;
} ;

bool bstIsInit=false;
bool insertMultiple=false;


int bstSize=0;
/** bst list     */
list<node> bst;


/**  commands declaration */
void info();
void init();
bool insert(int k);
void keySet(struct node *n);
void keySet2();
void insertN(int n);
void find(int k);
void deleteN(int k);

int main()
{



info();
string command;
while(1)
{
          cin>>command;
    if(command.compare("init")==0){
        init();
     }
     else if(command.compare("info")==0)
     {
            info();
     }
     else if(command.find("insert(",0)!=-1 && (command.compare("insert(")!=0))
     {
        int sign=1;
        int key=0;
        string cmp="insert(";
        for(int i=0;i<command.size();++i)
       {
            if(i==cmp.length())
            {
                if(command[i]=='-')
                    {sign=-1;
                    i++;
                    }
                    bool ok=false;
                    int j=i;
                 while(j<command.size()-1)
                 {
                    if(command[j]-'0'>=0 && command[j]-'0'<=9)
                        {
                        ok=true;
                            key*=10;
                            key+=command[j]-'0';
                        }
                    else
                    {
                        ok=false;
                       break;
                    }
                    j++;
                 }
                 if(!ok)
                 {
                    cout<<"wrong character in command insert"<<endl;
                       i=command.size();
                    break;
                 }
                 else if(command[j]==')' && j==command.size()-1)
                        {
                           insert(key*sign);
                            i=command.size();
                            break;
                        }
             }
             else if(command[i]!=cmp[i])
            {
                cout<<"wrong command"<<endl;
                break;
             }


       }

     }
     else if(command.compare("keySet")==0)
         {
                  if(bstIsInit)
                        {
                        if(bst.size()!=0)
                              keySet(&(*(bst.begin())));
                        else
                              cout<<"Empty tree"<<endl;
                        }
                  else
                        cout<<"bst not initialized"<<endl;
         }
         else if(command.compare("exit")==0)
        break;
       else if(command.substr(0,8).compare("insertN(")==0)
       {
             stringstream ss(command.substr(8,command.size()-9));
             int arg=-1;
            ss>>arg;
            int s=ss.str().size();
            stringstream ss2("");
            ss2<<arg;
            int s2=ss2.str().size();
            if(arg<=-1)
                  cout<<"Wrong insertN(key) command format"<<endl;
            else if(s2==s && *(--(command.end()))==')')
                insertN(arg);
            else
                  cout<<"Wrong command insertN"<<endl;

       }
        else if(command.substr(0,8).compare("deleteN(")==0)
       {
             stringstream ss(command.substr(8,command.size()-9));
             int arg=-1;
            ss>>arg;
            int s=ss.str().size();
            stringstream ss2("");
            ss2<<arg;
            int s2=ss2.str().size();

            if(s2==s && *(--(command.end()))==')')
                deleteN(arg);
            else
                  cout<<"Wrong command delete"<<endl;

       }
       else if(command.compare("keySet2")==0)
            keySet2();
     else {
        cout<<"Wrong Command"<<endl;

      }




}


    return 0;
}

/********************************************************/
/**         info                                                           */
void info()
{
      cout<< "  |";
    for(int i=0;i<screenWidth;++i)
    {
            cout<<'*';
    }
      cout<<"|"<<endl;
      cout<<"  |\t COMMAND DESCRIPTION \t\t   |"<<endl;
      cout<< "  |";
    for(int i=0;i<screenWidth;++i)
    {
            cout<<'*';
    }
      cout<<"|"<<endl;
     //*************************************************************
     //      init
      cout<<"  | init          -- create empty bst      |"<<endl;
      //*************************************************************
     //      info
      cout<<"  | info          -- displays commands     |"<<endl;
      //*************************************************************
     //     insert(key)
      cout<<"  | insert(key)   -- inserts node to bst   |"<<endl;
      //*************************************************************
      //     insertN(n)
      cout<<"  | insertN(n)    -- inserts n nodes\t   |"<<endl;
      //*************************************************************
      //    find(key)
      cout<<"  | find(key)     -- finds node \t   |"<<endl;
      //*************************************************************
      //     deleteN(key)
      cout<<"  | deleteN(key)   -- delets node\t   |"<<endl;
      //*************************************************************
       //   keySet
       cout<<"  | keySet        -- displays all keys\t   |"<<endl;
      //*************************************************************
        //  exit
       cout<<"  | exit          -- turns off program\t   |"<<endl;
      //*************************************************************
      cout<< "  |";
      for(int i=0;i<screenWidth;++i)
          {
                  cout<<'*';
          }
      cout<<"|"<<endl;
return;
}
/********************************************************/
/**         init                                                            */
void init()
{
      bst=list<node>(0);
      bstIsInit=true;
   return;
}


/********************************************************/
/**         insert(key)                                              */
bool insert(int key)
{
if(bstIsInit)
{
if(bst.empty())
      {
       struct node root;
      root.key=key;
      root.leftChild=NULL;
      root.rightChild=NULL;
        bst.push_back(root);
         (--bst.end())->position=(--bst.end());
      bstSize++;
      }
      else
      {
             struct node *temp=&(*bst.begin());

                   while(1)
                  {
                        if((key < (temp->key)) )
                        {
                             if ((temp->leftChild)!=NULL)
                                   {

                                   temp=(temp->leftChild);
                                       }
                              else
                              {
                                   node newNode;
                                    newNode.key=key;
                                    newNode.rightChild=NULL;
                                    newNode.leftChild=NULL;
                                      bst.push_back(newNode);
                                       (--bst.end())->position=(--bst.end());

                                    (temp->leftChild)=&(*(--bst.end()));
                                      bstSize++;
                                    break;
                              }

                          }
                        else if((key > (temp->key)) )
                              {
                                     if ((temp->rightChild)!=NULL)
                                          temp=(temp->rightChild);
                                    else
                                    {
                                        node newNode;
                                          newNode.key=key;
                                          newNode.rightChild=NULL;
                                          newNode.leftChild=NULL;
                                           bst.push_back(newNode);
                                          (--bst.end())->position=(--bst.end());
                                    (temp->rightChild)=&(*(--bst.end()));
                                             bstSize++;
                                          break;
                                    }
                              }
                              else if(!insertMultiple)
                                  {  cout<<"There exist node with key "<<key<<endl;
                                    return false;
                                   }
                  }

      }
   }
   else
     {
            cout<<"Can't insert to bst without initialization"<<endl;
            return false;
      }
return true;
}
/********************************************************/
/**        keySet                                                      */
void keySet(struct node* n)
{
      if(n!=NULL)
            {
                  keySet(n->leftChild);
                  cout<<"key: "<<n->key<<endl;
                  keySet(n->rightChild);
            }

return;
}
/********************************************************/
/**        keySet   2                                                   */
void keySet2()
{
      for(list<node>::iterator i=bst.begin();i!=bst.end();++i)
            {
            cout<<"klucz: "<<i->key<<endl;
            if((i->leftChild )!= NULL)
                  cout<<"lewy: "<<(i->leftChild)->key<<endl;
                  else
                  cout<<"lewy: null"<<endl;
             if((i->rightChild )!= NULL)
            cout<<"prawy: "<<(i->rightChild)->key<<endl;
            else
                  cout<<"prawy: null"<<endl;
            }


return;
}
/********************************************************/
/**        insertN(n)                                                 */
void insertN(int n)
{
      insertMultiple=true;
      if(bstIsInit)
      {
            srand(time(NULL));
            int i=0;
            while(i<n)
            {
                 if(insert(rand()))
                        i++;
            }
      }
      else
            cout<<"Can't insert to bst without initialization"<<endl;
      insertMultiple=false;


      return;
}
/********************************************************/
/**        find(key)                                                */
void find(int k)
{
      if(bstSize>0)
      {
            struct node *temp=&(*bst.begin());
             while(1)
                  {
                        if((k < (temp->key)) )
                        {
                             if ((temp->leftChild)!=NULL)
                                   {

                                   temp=(temp->leftChild);
                                       }
                              else
                              {
                                   cout<<"No node with key "<<k<<" in bst"<<endl;
                                    break;
                              }

                          }
                        else if((k > (temp->key)) )
                              {
                                     if ((temp->rightChild)!=NULL)
                                          temp=(temp->rightChild);
                                    else
                                    {
                                        cout<<"No node with key "<<k<<" in bst"<<endl;
                                         break;
                                    }
                              }
                              else
                                  {  cout<<"Node with key"<<k<<" found:"<<endl;
                                       break;

                                   }
                  }

      }
      else
      {
            cout<<"Nothing to find, empty bst"<<endl;
      }
return;
}
/********************************************************/
/**        delete(key)                                                */
void deleteN(int k)
{
if(bstSize>0)
{

      struct node *temp=&(*(bst.begin()));
       struct node *parent=NULL;
      bool isRight=false;
      while(1)
      {
                        if((k < (temp->key)) )
                        {
                             if ((temp->leftChild)!=NULL)
                                   {
                                   parent=temp;
                                   isRight=false;

                                   temp=(temp->leftChild);
                                       }
                              else
                              {
                                   cout<<"No node with key "<<k<<" in bst"<<endl;
                                    break;
                              }

                          }
                        else if((k> (temp->key)) )
                              {
                                     if ((temp->rightChild)!=NULL)
                                         {
                                                      parent=temp;
                                                isRight=true;
                                                temp=(temp->rightChild);

                                               }
                                    else
                                    {
                                        cout<<"No node with key "<<k<<" in bst"<<endl;
                                         break;
                                    }
                              }
                              else
                                  {
                                          if(temp->leftChild==NULL && temp->rightChild==NULL)
                                          {
                                                if(parent!=NULL)
                                                      (isRight?parent->rightChild:parent->leftChild)=NULL;
                                                 bst.erase(temp->position);
                                                 bstSize--;
                                          }
                                          else if(temp->leftChild!=NULL && temp->rightChild==NULL)
                                          {
                                           if(parent!=NULL)
                                                (isRight?parent->rightChild:parent->leftChild)=temp->leftChild;
                                                 bst.erase(temp->position);
                                                 bstSize--;

                                          }
                                          else if(temp->leftChild==NULL && temp->rightChild!=NULL)
                                          {
                                                (isRight?parent->rightChild:parent->leftChild)=temp->rightChild;
                                                 bst.erase(temp->position);

                                          }
                                          else
                                          {
                                                      list<node>::iterator i=temp->position;
                                                      struct node* parent2=parent;
                                                      temp=temp->rightChild;



                                               while( (temp->leftChild!=NULL))
                                                      {
                                                            parent2=temp;
                                                             temp=temp->leftChild;
                                                      }
                                                     parent2->leftChild=temp->rightChild;
                                                     i->key=temp->key;
                                                     bst.erase(temp->position);
                                                     bstSize--;
                                          }


                                          break;


                                   }
                  }
}
else
{
      cout<<"Can't delete from empty bst"<<endl;
}
return;
}
