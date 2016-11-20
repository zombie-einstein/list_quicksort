#include <list>

// Pop of first member of list L1, and push to list L2
template<class x>
void pop1_push2(std::list<x> &L1, std::list<x> &L2){
  
  L2.push_back(L1.front());
  L1.pop_front();
}

// Splice list L2 onto the end of list L1
template<class x>
void joinLists(std::list<x> &L1, std::list<x> &L2){
  
  L1.splice(L1.end(),L2);
}

// Recursive quickSort function, takes an unsorted list, and an empty result list as arguments
template<class x>
void listQuickSort(std::list<x> &toSort, std::list<x> &result){
    
    // Recursion terminates here, push single member to result list
    if( toSort.size()<2 ){ 
      joinLists<x>(result,toSort);
      return;
    }
    
    // Lists used to sort results
    std::list<x> left,middle,right;
    
    // Sort each list member into a list using pivot
    while(toSort.begin()!=toSort.end()){
      if(toSort.front()<toSort.back()){ pop1_push2<x>(toSort,left);}
      else if(toSort.front()>toSort.back()){ pop1_push2<x>(toSort,right);}
      else{ pop1_push2<x>(toSort,middle);}
    }
    
    // Recursive call on left and right, join middle list
    listQuickSort<x>(left,result);
    joinLists<x>(result,toSort);
    listQuickSort<x>(right,result);
}
