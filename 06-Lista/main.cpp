#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }

};

struct SList{
    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
    head = deletarTudo(head);
    }

    SList( string ){
    head = deletarTudo(head);
    }



    //função recursiva: ponto de parada, ação e redução do problema
    Node * deletarTudo(Node * node){
        if(node == nullptr)
            return 0;
        deletarTudo(node->next);//andando até o último não nulo
        delete node;//deletando os valores encontrados
        return nullptr;
    }
    /*   1234567890
             5
         12345
*/
    Node * arrancaRabo(Node * node, int value){
       if(node == nullptr)
            return 0;
       node->next = arrancaRabo(node->next, value);//atualizando o next
        if(node->next == nullptr){ // se ele for nulo
            if(node->value != value){ // testa o valor do anterior
                delete node;
                return nullptr;
            }else{
                return node;
            }
        }
         node->next = arrancaRabo(node->next, value);
        return node;
    }

    //diferença do deletar tudo:
    //começar do fim e apagar até o nó
    Node * arrancaVenta(Node * node, int value){
        if(node == nullptr)
            return 0;
        while(node->next->value != value ){
            return 0;
        }
        deletarTudo(node->next);//andando até o último não nulo
        delete node;//deletando os valores encontrados
        return nullptr;
   }



    //Iterativo ->feito em sala com Sávila e Ronaldo
    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    //Recursivo
    Node * _rinserir_ordenado(Node * node, int value){
        if(node == nullptr || (node->value >= value))
           return new Node(value, node);
        node->next = _rinserir_ordenado(node->next, value);
        return node;
    }

    void rinserir_ordenado(int value){
        head = _rinserir_ordenado(head, value);
    }


//Lembro que fiz em sala
    int r_somar(Node * node){
        if(node->value == NULL)
            return 0;
        if(node->next->value == NULL)
            return node->value;
        return node->value + r_somar(node->next->value);
   }

    void somar(){
        cout << r_somar(head) << endl;
   }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }
    //Push_back
    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }
    //Push_back recursivo
    Node * _rpush_back(Node * node, int value){
            if(node == nullptr)
                return new Node(value);
            node->next = _rpush_back(node->next, value);
            return node;
    }

    void rpush_back(int value){
            head = _rpush_back(head, value);
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }
    //Pop_back recursivo
    Node * _rpop_back(Node * node){
            if(node->next == nullptr){
                delete node;
                return nullptr;
            }
            node->next = _rpop_back(node->next);
    }

    void rpop_back(){
            this->head = _rpop_back(head);
    }


    void show(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
    //Show  recursivo private
    void _rshow(Node * node){
        if(node == nullptr)
            return;

        cout << node->value << " ";
        _rshow(node->next);
    }
    //Show recursivo public
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    //ação
    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
}
    //recursividade
    void remove(int value){
        head = _remove(head, value);
    }

    int size(){
            int size = 0;
            auto node = head;
            while(node != nullptr){
                node = node->next;
                size++;
            }
            return size;
     }

};


int main(){
    SList l;
    l.push_back(8);
    l.push_back(3);
    l.push_back(2);
    l.push_back(6);
    l.push_back(4);
    l.rshow();
   // cout << l.rsomar(l.head);        Não aceita a soma mesmo sendo do mesmo tipo meu sem or
    l.remove(8);
    l.rshow();
    //l.arrancaRabo(lista.head, 4);         Não funciona omg
    l.arrancaVenta(lista.head, 3);
    l.rshow();
    return 0;
}
