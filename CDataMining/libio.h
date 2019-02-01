/* LIB-io
*	A simple library to read and write data
*
* 05/28/2017
* @debarron, @ifvega
*/

#ifndef LIBIO_H
#define LIBIO_H

// Data types labes, showed in the TMT metadata file
#define PERIODIC_LABEL "PERIODIC"
#define NOMINAL_LABEL  "NOMINAL"
#define INTEGER_LABEL  "INTEGER"
#define ORDINAL_LABEL  "ORDINAL"
#define REAL_LABEL 		 "REAL"

// The value for this data types follows no convention
#define PERIODIC_ID	5
#define NOMINAL_ID	1
#define INTEGER_ID	2
#define ORDINAL_ID	4
#define REAL_ID	3



/* Etiquetas que indican los tipos del archivo TMT */
#define TIPO_1 "NOMINAL"
#define TIPO_2 "ENTERO"
#define TIPO_3 "REAL"
#define TIPO_4 "ORDINAL"
#define TIPO_5 "PERIODO"

#define NOMINAL	1
#define ENTERO	2
#define REAL	3
#define ORDINAL	4
#define PERIODO	5



/* El formato del archivo TMT es el siguiente:
 *
 * nombre_variable TIPO X
 *
 * El nombre variable no debe contener espacios en
 * blanco. El tipo debe ser cualquiera de los descritos
 * anteriormente, donde cada tipo obedece a la naturaleza
 * de la variable. La X es necesaria, considerada para
 * futuras implementaciones.
 * */

 union value_t{
 	double real_value;
 	long integer_value;
 };

#define BUFF 512
typedef struct _attr{
	value_t value;
	char *string_value;
}attribute_t;

typedef struct{
	int attribute_type;
	char attribute_name;
	int min, max;
	char **elementos;
	int elementos_len;
}esquema_t;

typedef struct{
	esquema_t *esquema;
	atributo **tuplas;
	int esquema_len;
	int tuplas_len;
}relacion;





typedef struct _atr{
	union _v{
		float valor_f;
		int valor_i;
	}v;
	char *cadena;
}atributo;

typedef struct{
	int tipo;
	char *nombre;

	/* Futura implementacion */
	int min, max;

/*********************************************/
/******* ATUALIZACIÓN 14-OCT-2012 ************/
/*** RECONOCE LAS CLASES DE LOS NOMINALES ****/
/*********************************************/
	char **elementos;
	int elementos_len;
/*********************************************/

}esquema_t;

typedef struct{
	esquema_t *esquema;
	atributo **tuplas;
	int esquema_len;
	int tuplas_len;
}relacion;


esquema_t* lectura_obtener_esquema(FILE *archivo_tmt, int *esquema_len);

relacion* lectura_obtener_relacion(FILE *archivo_datos, esquema_t *esquema, int esquema_len);

#endif
