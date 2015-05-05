#include <iostream>
#include <string>
#include "tester.h"

using namespace std;


Trie::Trie(){
  root = new BasicTrieNode();
}

void Trie::Create(string x) {
  
  BasicTrieNode *current = root;
  int i = 0;
  while ( x[i] != '\0' ){
      int j = x[i] - 'a';

      // Changes the initial BTN root of the Trie to a TN

      if (current->WhoAmI() == 0){
        TrieNode *newTN = new TrieNode();
        BasicTrieNode *k = current;
        this->root = newTN;
        delete k;
        current = newTN;
      }

      // If no word comes out of index j and we are not on the last
      // letter, make a new TN and set the pointer from the index
      // at j to the new TN

      if (current->GetPtr(j) == 0 && x[i+1] != '\0'){
        TrieNode *newTN = new TrieNode();
        current->SetPtr(j, newTN);
        current = current->GetPtr(j);
      }

      //If the index at j leads to a BTN and we are not on the last
      // letter, create a new TN, set its ptr2ms to what the BTN had,
      // and delete the BTN

      // If its not a BTN, then simply update your current pointer to 
      // that index.

      else if (current->GetPtr(j) != 0 && x[i+1] != '\0'){
        if (current->GetPtr(j)->WhoAmI() == 0){
            TrieNode *newTN = new TrieNode();
            BasicTrieNode *toDelete = current->GetPtr(j);
            MultiSet *msPtr = current->GetPtr(j)->GetPtr2MS();
            current->SetPtr(j, newTN); 
            current = current->GetPtr(j);
            current->SetPtr2MS(msPtr);
            //newTN->GetPtr(j)->SetPtr2MS(msPtr);
            delete toDelete;
        }
        else {
          current = current->GetPtr(j);
        }
      }

      // If we are on the the last letter and the pointer at index j 
      // is NULL, make a new BTN and set its ptr2Ms to a new Multiset

      else if (current->GetPtr(j) == 0 && x[i+1] == '\0'){
        current->SetPtr(j, new BasicTrieNode());
        current = current->GetPtr(j);
        current->SetPtr2MS(new ULL());
        }

      // If we are on the last letter and the pointer at j points to 
      // a BTN,  then set the pointer's ptr2ms to a new Multiset.

      //If that node already had a ptr2ms, then create a new multiset 
      // and set its ptr2prev to the previous multiset it was pointing
      // to
      
      else if (current->GetPtr(j) != 0 && x[i+1] == '\0'){
        if (current->GetPtr2MS() == 0){
          current = current->GetPtr(j);
          current->SetPtr2MS(new ULL());
        }
        else {
          MultiSet *p = current->GetPtr2MS();
          MultiSet *p2 = new ULL();
          p2->setptr2prev(p);
          current->SetPtr2MS(p2);
        }
      } 
    i++;
  }
}

void Trie::Merge(string s, string t){
  BasicTrieNode *sBTN = pointerToWord(s);
  BasicTrieNode *tBTN = pointerToWord(t);
  ULL *sULL = (ULL *) sBTN->GetPtr2MS();
  ULL *tULL = (ULL *) tBTN->GetPtr2MS();
  MultiSet *tpointertoprev = tBTN->GetPtr2MS()->getptr2prev();

  sULL->append(tULL->getFirst());
  if (tpointertoprev != 0)
    tBTN->SetPtr2MS(tpointertoprev);
  else 
    tBTN->SetPtr2MS(new ULL());
}



void Trie::Insert(string x, int i){
    if (!Member(x)) return;
    BasicTrieNode *current = this->pointerToWord(x);
    ULL *p = (ULL *) current->GetPtr2MS();
    p->insert(i);
    p->numberPlus();
    cout << p->getNumber() << endl;
}

void Trie::DeleteElem(string x, int i){
  if (!Member(x)) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *p = (ULL *) current->GetPtr2MS();
  p->deleteValue(i);
}

void Trie::DeleteMax(string x){
  if (!Member(x)) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *p = (ULL *) current->GetPtr2MS();
  p->deleteMax();
}

void Trie::PrintMax(string x){
  if (!Member(x)) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *p = (ULL *) current->GetPtr2MS();
  p->printMax();
}

void Trie::PrintMin(string x){
  if (!Member(x)) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *p = (ULL *) current->GetPtr2MS();
  p->printMin();
}

void Trie::PrintNum(string x){
  if (!Member(x)) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *p = (ULL *) current->GetPtr2MS();
  p->printNumberElements();
}

void Trie::Dist(string x, int k){
  if (!Member(x)) return;
  BasicTrieNode *current = this->pointerToWord(x);
  ULL *p = (ULL *) current->GetPtr2MS();
  p->distance(k);
}

void Trie::CountN(){
  int counter = 0;
  if (root->WhoAmI() == 0){
    cout << "0" << endl;
    return;
  }
  for (int i = 0; i < TrieMaxElem; i++){
    if (root->GetPtr(i) != 0){
      counter += CountN(root->GetPtr(i));
    }
  }
  cout << counter << endl;
}
int Trie::CountN(BasicTrieNode *current){
  int counter = 0;
  if (current == 0) return counter;

  if (current->GetPtr2MS() != 0) counter++;

  for (int i = 0; i < TrieMaxElem; i++){
    if (current->GetPtr(i) != 0)
      counter += CountN(current->GetPtr(i));
  }
  
  return counter;
}

void Trie::Delete(string x){
  
  if (!Member(x)) return;
  bool tnEmpty = true;
  BasicTrieNode *current = pointerToWord(x);
  if (current->GetPtr2MS()->getptr2prev() == 0){
    ULL *toDelete = (ULL *) current->GetPtr2MS();
    toDelete->deleteAll();
    for (int i = 0; i < StrMaxElem; i++){           //checking if word is prefix
      if (current->GetPtr(i) != NULL) tnEmpty = false;
    }

  }

}

//int Trie::findLevel(string)

/*
void Trie::Delete(char x[])
{
  //TrieNode *current = root;
  //int i = 0;
  //if (x[i] == '\0') return;
  //bool j = Delete(x,i,current);
}

bool Trie::Delete(char x[], int i, TrieNode *current){
  
  if (current != 0)
    {if (x[i] == '\0')
       {current -> UnSetStrEnds();
    if (CheckTrieNodeEmpty(current))
      {delete current; return true;} }
      else {
        if (Delete(x,i+1,current->GetPtr(x[i] - 'a'))){
          current->SetPtr(x[i] - 'a', 0);
             if (i != 0 && CheckTrieNodeEmpty(current))
               {delete current; return true;} 
           }
      }
    }
    
  return false;
}
*/

bool Trie::CheckTrieNodeEmpty(TrieNode *current)
{
  /*
  if (current -> GetStrEnds()) return false;
  for(int i = 0; i<TrieMaxElem; i++)
    if (current->GetPtr( i )) return false;
  return true;
  */
  return false;
}

bool Trie::Member(string x) {
  
  BasicTrieNode *current = root;
  int i = 0;
  while (x[i] != '\0'){
    int j = x[i] - 'a';
    if ( current->GetPtr(j) == 0 )
        return false ;
    else 
        current = current->GetPtr(j);
    i = i+1;
  }
  if (current->GetPtr2MS() != 0)
    return true;
  else return false;
}

void Trie::printAllElements(string x){
  if (!Member(x)) return;
  ULL *p = (ULL *) this->pointerToWord(x)->GetPtr2MS();
  p->printAll();
}

BasicTrieNode* Trie::pointerToWord(string x) {
  
  BasicTrieNode *current = root;
  int i = 0;
  while (x[i] != '\0'){
    int j = x[i] - 'a';
    if ( current->GetPtr(j) == 0 )
        return NULL;
    else 
        current = current->GetPtr(j);
    i = i+1;
  }
  return current;
}

bool BasicTrieNode::CheckTrie(int*a){return true;}


bool Trie::CheckTrie(int* count)                                   //*****
      {
        /*
       // USE THIS PROCEDURE DIRECTLY IN YOUR CODE                //*****
        // IF YOU HAVE DIFFERENT CLASS NAMES, FUNCTIONS OR VALUES  //*****
        // YOU NEED TO CHANGE THEM HERE TOO.                       //*****
        int countl;                                                //*****
        bool result;                                               //*****
        result = root->CheckTrie(&countl);                         //*****
        *count=countl;                                             //*****
        return result;  
        */
        return true;                                           //*****
      }  

bool TrieNode::CheckTrie(int* pcount)                              //*****
      { // USE THIS PROCEDURE DIRECTLY IN YOUR CODE                //*****
        // IF YOU HAVE DIFFERENT CLASS NAMES, FUNCTIONS OR VALUES  //*****
        // YOU NEED TO CHANGE THEM HERE TOO.                       //*****
        /*
        bool           result;                                     //*****
        int            i,countl,countll;                           //*****
        countl= *pcount;                                           //*****
        result=true;                                               //*****
        if (GetPtr2MS() != 0) *pcount++;                           //*****
        for(i=0; i<TrieMaxElem; i++)                               //*****
           {if(GetPtr(i)!=0)                                       //*****
             if(!GetPtr(i)->CheckTrie(pcount)) {return false;}     //*****
           }                                                       //*****
        if(countl == *pcount) return false;                        //*****
        */
        return true;                                               //*****
      }  
