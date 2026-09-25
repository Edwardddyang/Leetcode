//Create MinStack object where getMin() is O(1) 
//Cant do int min tracker as a variable because if you pop the minimum value, you lose track of the next minimum value
class MinStack { //WRONG ANSWER 
private: 
    stack<int> val; 
    int minimum = 0; 
public:
    MinStack() {
        
    }
    
    void push(int value) {
        minimum = min(minimum, value); 
        val.push(value); 
    }
    
    void pop() {
        val.pop(); 
    }
    
    int top() {
        return val.top();
    }
    
    int getMin() {
        return minimum; 
    }
};

//RIGHT ANSWER
class MinStack {
private: 
    stack<int> seen; 
    stack<int> minimum; 
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(minimum.size() == 0)
            minimum.push(value); 
        //Make sure its "else if", or else after addign the first value to minimum, it will add it again to the same minimum stack since its <= 
        else if(value <= minimum.top()) //Make sure its <= or else if you have 2 of the same minimum value, it will only pop 1 of them and lose track of the other minimum value
            minimum.push(value); 
        seen.push(value); 
    }
    
    void pop() {
        if(seen.top() == minimum.top())
            minimum.pop(); 
        seen.pop(); 
    }
    
    int top() {
        return seen.top(); 
    }
    
    int getMin() {
        return minimum.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */