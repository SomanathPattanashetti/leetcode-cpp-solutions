// Leetcode Problem: 901. Online Stock Span
// Link: https://leetcode.com/problems/online-stock-span/
// Difficulty: Medium
// Tags: Stack, Monotonic Stack, Design

// ✅ Approach:
// Use a **Monotonic Decreasing Stack**.
// Each stack element stores a pair:
//   {price, span}
//
// The span of a stock price is defined as the number of
// consecutive days (including today) the price was
// less than or equal to today's price.
//
// 🔹 Idea:
// - Maintain a stack where prices are in decreasing order.
// - When a new price comes:
//     - Pop all previous prices that are <= current price
//     - Accumulate their spans
// - Push the current price along with its computed span
//
// This ensures each element is pushed and popped only once,
// giving an amortized O(1) time complexity per operation.

class StockSpanner {
public:
    // Stack stores {price, span}
    stack<pair<int,int>> stk;

    // Constructor
    StockSpanner() {
        // No initialization needed
    }
    
    int next(int price) {
        
        // Minimum span is always 1 (current day)
        int span = 1;

        // Pop elements while previous price <= current price
        // and accumulate their spans
        while(!stk.empty() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }

        // Push current price with its computed span
        stk.push({price, span});

        // Return the span for current price
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
