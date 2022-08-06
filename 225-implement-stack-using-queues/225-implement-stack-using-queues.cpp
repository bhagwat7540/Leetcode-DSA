class MyStack {
public:
    queue<int> q1 , q2;
    MyStack() {
    }
    
    void push(int x) {
        if(q1.empty() && q2.empty()) q1.push(x);
        else if(q2.empty()) q1.push(x);
        else q2.push(x);
    }
    
    int pop() {
        if(!q1.empty()){
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            
            int x = q1.front();
            q1.pop();
            return x;
        }
        else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int x = q2.front();
            q2.pop();
            return x;
        }
    }
    
    int top() {
        if(!q1.empty()){
            int x;
            while(!q1.empty()){
                x = q1.front();
                q2.push(x);
                q1.pop();
            }
            
            return x;
        }
        else{
            int x;
            while(!q2.empty()){
                x = q2.front();
                q2.pop();
                q1.push(x);
            }
            return x;
        }
        
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */