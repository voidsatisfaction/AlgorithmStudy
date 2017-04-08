/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: admin
 *
 * Created on 2016년 10월 25일 (화), 오후 5:37
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
class Node{
public:
    int data;
    Node *tail;
};
class LinkedList{
    Node *listhead;
    Node *tempnode;
    void add(int data){
        Node *temp = new Node();
        temp->data = data;
        if(listhead == NULL){
            listhead == temp;
        }else{
            tempnode = listhead;
            while(tempnode->tail != NULL){
            tempnode = tempnode->tail;
            }
            tempnode->tail = temp;
        }
    }
    void del(int num){
        if(num == 1){
            delete listhead;
            listhead = NULL;
        }else{
            Node *temptemp;
            tempnode = listhead;
        
            for(int i=0;i<num-2;i++){
            tempnode = tempnode->tail;
            if(tempnode->tail->tail == NULL){
                return;
            }
        }
        temptemp = tempnode->tail;
        tempnode->tail = tempnode->tail->tail;
        delete temptemp;
    }
};

int main(int argc, char** argv) {

    return 0;
}

