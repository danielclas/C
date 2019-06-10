#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList *)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<this->size){
        if(nodeIndex==0){
            pNode=this->pFirstNode;
        }else{
            pNode=this->pFirstNode;
            while(nodeIndex>0){
                pNode=pNode->pNextNode;
                nodeIndex--;
            }
        }
    }

   /**Retorna un puntero al nodo que se encuentra en el índice especificado.
    Verificando que el puntero this sea distinto de NULL y que index sea
        positivo e inferior al tamaño del array. Si la
    verificación falla la función retorna (NULL) y si tiene éxito retorna el puntero al nodo.**/

    return pNode;
}


/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode=(Node*) malloc(sizeof(Node));

    Node* prevNode=NULL;
    Node* nextNode=NULL;

    if(this!=NULL && nodeIndex<=this->size && nodeIndex>=0){
        if(nodeIndex==0 && this->size==0){
            this->pFirstNode=newNode;
            this->pFirstNode->pElement=pElement;
            this->pFirstNode->pNextNode=NULL;
            this->size++;
            returnAux=0;
            /**
                Si el index recibido es 0 y el tamaño del ll es 0,
                lo agrega al indice 0 con pNextNode=NULL;
            **/
        }else{
            if(nodeIndex==0 && this->size!=0){
                /**
                    Si el index recibido es 0 y el tamaño del ll es distinto a 0,
                    el pFirstNode del ll es el nuevo nodo, y este apunta al nodo
                    anteriormente en posicion 0.
                **/
                nextNode=getNode(this, 0);
                this->pFirstNode=newNode;
                this->pFirstNode->pElement=pElement;
                this->pFirstNode->pNextNode=nextNode;
                this->size++;
                returnAux=0;
            }else{
                if(nodeIndex==this->size){
                    /**
                        Si el index recibido es igual al size del ll,
                        se agrega un nuevo nodo al final de este
                        haciendo que el ultimo nodo actual apunte al nuevo nodo,
                        y que este tenga pNextNode=NULL.
                    **/
                    prevNode=getNode(this, nodeIndex-1);
                    newNode->pElement=pElement;
                    newNode->pNextNode=NULL;
                    prevNode->pNextNode=newNode;
                    this->size++;
                    returnAux=0;
                }else{
                    /**
                        Obtengo el nodo siguiente y el anterior al nodo en el nodeIndex recibido.
                        En el indice anterior, pNextNode sera igual al nuevo nodo,
                        y el pNextNode del nuevo nodo sera el obtenido en nextNode;
                    **/
                    prevNode=getNode(this, nodeIndex-1);
                    nextNode=getNode(this, nodeIndex+1);
                    prevNode->pNextNode=newNode;
                    newNode->pNextNode=nextNode;
                    newNode->pElement=pElement;
                    this->size++;
                    returnAux=0;
                }
            }
        }
    }

    return returnAux;
}

/**Agrega un nodo en la posición indexNode.
 Verificando que el puntero this sea distinto de NULL
y que index sea positivo e inferior al tamaño del array.
Si la verificación falla la función retorna
(-1) y si tiene éxito (0).**/


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this!=NULL){
        index=this->size;
        returnAux=addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* node;

    if(this!=NULL && index>=0 && index<this->size){
        node=getNode(this, index);
        if(node->pElement!=NULL){
            returnAux=(void*)node->pElement;
        }
    }

    return returnAux;
}

/**Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.**/

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* node;

    if(this!=NULL && index>=0 && index<this->size){
        node=getNode(this, index);
        node->pElement=(void*)pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* node;
    Node* nextNode;
    Node* prevNode;

    if(this!=NULL && index>=0 && index<this->size){
       if(index==0 && this->size>2){
            /**
                Si el nodo a eliminar es el primero y la lista tiene mas de 2 elementos,
                el elemento 1 tomara la posicion del elemento 0, y se reducira el tamaño
                del ll.
            **/
                node=getNode(this, 1);
                this->pFirstNode->pNextNode=node->pNextNode;
                this->pFirstNode->pElement=node->pElement;
                this->size--;
                returnAux = 0;
       }else{
           if(index==0 && this->size==1){
                /**
                    Si el nodo a eliminar es el primero y la ll tiene tamaño 1,
                    el pFirstNode de la ll es el eliminado, y se reduce el tamaño
                    de la lista
                **/
                this->pFirstNode=NULL;
                this->size--;
                returnAux = 0;
           }else{
               /**
                    Si el elemento a eliminar es el siguiente al pFirstNode,
                    se establece al nodo en el indice 2 como pNextNode de
                    pFirstNode, y se reduce el tamaño de la lista.
               **/
                if(index==1){
                node=getNode(this, index);
                nextNode=getNode(this, index+1);
                this->pFirstNode->pNextNode=nextNode;
                this->size--;
                node=NULL;
                returnAux = 0;
           }else{
               /**
                    Si el elemento a eliminar es cualquier otro,
                    el nodo anterior al deseado apuntara al siguiente,
                    y se seteara como NULL al nodo a eliminar.
                    Se recude el tamaño de la lista en 1.
               **/
                node=getNode(this, index);
                nextNode=getNode(this, index+1);
                prevNode=getNode(this, index-1);
                prevNode->pNextNode=nextNode;
                this->size--;
                node=NULL;
                returnAux = 0;
           }
           }

       }
    }

    return returnAux;}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* node;

    if(this!=NULL){
        if(this->size==1){
            this->pFirstNode=NULL;
            this->size--;
            returnAux=0;
        }else{

            this->pFirstNode=NULL;
            for(int i=this->size-1 ; i>0 ; i--){
                node=getNode(this, i);
                node=NULL;
                this->size--;
            }

            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* node;

    if(this!=NULL && this->size>0){
        if(this->pFirstNode->pElement==pElement){
            returnAux=0;
        }else{
            for(int i=this->size-1 ; i>1 ;i--){
                node=getNode(this, i);
                if(node->pElement==pElement){
                    returnAux=i;
                    break;
                }
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        if(this->pFirstNode!=NULL){
            returnAux=0;
        }else{
            returnAux=1;
        }
    }

    return returnAux;
}




/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux=-1;

    if(this!=NULL && index>=0 && index<=this->size){
        returnAux=addNode(this, index, pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* node;

    if(this!=NULL && index>=0 && index<this->size){
        node=getNode(this, index);
        returnAux=(void*)node->pElement;
        ll_remove(this, index);
    }

    return returnAux;
}



/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;

    if(this!=NULL){
        index=ll_indexOf(this, pElement);
        if(index>=0){
            returnAux=1;
        }else{
            returnAux=0;
        }
    }

    return returnAux;
}




/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

