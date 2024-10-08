#pragma once

#include "../data_structures/linkedList.hpp"
#include <unordered_set>
#include <queue>
#include <vector>

namespace CherryMath
{

template <typename T>
inline void reverse_linked_list(atl::List<T>& _list)
{
    if(!_list.head) { return; }

    atl::Node<T>* forward = nullptr;
    atl::Node<T>* prev = nullptr;
    atl::Node<T>* cur = _list.head;

    while(cur)
    {
        forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    _list.head = prev;
}

template <typename T>
inline void remove_duplicates(atl::List<T>& _list)
{
    if(!_list.head || !_list.head->next) return;
    std::unordered_set<T> numbers;

    atl::Node<T>* cur = _list.head;
    atl::Node<T>* prev = nullptr;
    while(cur)
    {
        if(numbers.count(cur->data))
        {
            atl::Node<T>* tmp = cur;
            cur = cur->next;
            prev->next = cur;
            delete tmp;
            tmp = nullptr;
        }
        else
        {
            numbers.insert(cur->data);
            prev = cur;
            cur = cur->next;
        }
    }
}

template<typename T>
inline bool find_cycle(atl::List<T> _list)
{
    if(!_list.head || !_list.head->next) return false;

    atl::Node<T> slow = _list.head->next;
    atl::Node<T> fast = _list.head->next->next;

    while(fast)
    {
        if(fast == slow) return true;
        else if(!fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

template <typename T>
inline atl::Node<T>* first_circular_node(atl::List<T> _list)
{
    if(!_list.head || !_list.head->next) return nullptr;
    atl::Node<T>* slow = _list.head->next;
    atl::Node<T>* fast = _list.head->next->next;

    while(fast && (fast != slow))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // If loop does not exist
    if (slow != fast)
        return nullptr;

    slow = _list.head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

template <typename T>
inline atl::List<T>* merge_sorted_lists(const std::vector<atl::Node<T>*>& lists)
{
    atl::List<T> result_list = new atl::List<T>(0);
    auto compare_function = [](atl::Node<T>* a, atl::Node<T>* b){ return a->val > b->val; };

    std::priority_queue<atl::Node<T>*, std::vector<atl::Node<T>*>, decltype(compare_function)> heap;

    for(auto node : lists)
    {
        heap.push(node);
    }

    while(!heap.empty())
    {
        atl::Node<T>* min_node = heap.top();
        heap.pop();
        result_list.push_back(min_node->val);
        if(auto node = min_node->next)
        {
            heap.push(node);
        }
    }

    return result_list;
}

}

