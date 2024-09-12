#ifndef COMP_H
#define COMP_H

/* Enumeración para los diferentes tipos de nodos */
typedef enum
{
    typeCon, /* Constante */
    typeId,  /* Identificador (variable) */
    typeOpr  /* Operador */
} nodeEnum;

/* Nodo para constantes */
typedef struct
{
    int value; /* Valor de la constante */
} conNodeType;

/* Nodo para identificadores (variables) */
typedef struct
{
    int i; /* Subíndice en la tabla de símbolos */
} idNodeType;

/* Nodo para operadores */
typedef struct
{
    int oper;                  /* Operador */
    int nops;                  /* Número de operandos */
    struct nodeTypeTag *op[1]; /* Operandos, extendido en tiempo de ejecución */
} oprNodeType;

/* Nodo principal, que puede ser constante, identificador u operador */
typedef struct nodeTypeTag
{
    nodeEnum type; /* Tipo de nodo */

    union
    {
        conNodeType con; /* Nodo para constantes */
        idNodeType id;   /* Nodo para identificadores */
        oprNodeType opr; /* Nodo para operadores */
    };
} nodeType;

/* Tabla de símbolos global */
extern int sym[26];

#endif
