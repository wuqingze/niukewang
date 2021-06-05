#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int val_):val(val_){}
};

class Queue{
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int n = 0;

    void push(int i){
        if(n == 0){
            head = new Node(i);
            tail = head;
        }else{
            tail->next = new Node(i);
            tail = tail->next;
        }
        n += 1;
    }

    int top(){
        if(n==0) return -1;
        return head->val;
    }

    int pop(){
        if(n==0) return -1;

        head = head->next;
        n -= 1;
        return 0;
    }

    int size(){ return n;}

    void clear(){
        n = 0;
        head = nullptr;
        tail = nullptr;
    }
};

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        Queue q;
        while(n-->0){
            string operation;
            cin>>operation;
            if("PUSH" == operation){
                int i;
                cin>>i;
                q.push(i);
            }else if("TOP" == operation){
                int res = q.top();
                cout<<res<<endl;
            }else if("SIZE" == operation){
                cout<<q.size()<<endl;
            }else if("POP" == operation){
                if(q.pop() == -1) cout<<-1<<endl;
            }else if("CLEAR" == operation){
                q.clear();
            }
        }
    }
    return 0;
}
