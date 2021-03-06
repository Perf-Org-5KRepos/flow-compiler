/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 27 "flow-parser.y"

#include <iostream>
#include "flow-ast.H"
#define YYNOERRORRECOVERY
#line 13 "flow-parser.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    flow_parserTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is flow_parserTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    flow_parserARG_SDECL     A static variable declaration for the %extra_argument
**    flow_parserARG_PDECL     A parameter declaration for the %extra_argument
**    flow_parserARG_STORE     Code to store %extra_argument into yypParser
**    flow_parserARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 71
#define YYACTIONTYPE unsigned char
#define flow_parserTOKENTYPE int
typedef union {
  int yyinit;
  flow_parserTOKENTYPE yy0;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define flow_parserARG_SDECL  flow_ast *ast ;
#define flow_parserARG_PDECL , flow_ast *ast 
#define flow_parserARG_FETCH  flow_ast *ast  = yypParser->ast 
#define flow_parserARG_STORE yypParser->ast  = ast 
#define YYNSTATE 114
#define YYNRULE 62
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    34,   93,   99,   98,    2,   59,   93,   99,   98,    9,
 /*    10 */    10,   11,   12,   13,    5,   29,   71,   72,    8,    7,
 /*    20 */     9,   10,   11,   12,   59,   93,   99,   98,  177,   28,
 /*    30 */    46,   24,   23,   42,   65,   94,   24,   23,   71,   72,
 /*    40 */    22,    6,   19,   21,    1,    4,   63,   59,   93,   99,
 /*    50 */    98,   27,   13,    5,   25,   24,   23,    8,    7,    9,
 /*    60 */    10,   11,   12,   95,   20,   55,   67,   93,   99,   98,
 /*    70 */    56,   93,   99,   98,   33,   41,   96,  104,   24,   23,
 /*    80 */   102,   50,   17,   52,   53,   92,    1,   66,  110,  109,
 /*    90 */    54,   31,    3,   56,   19,   78,   76,   24,   23,   14,
 /*   100 */    92,   24,   23,   70,  106,   43,   32,   85,   87,   54,
 /*   110 */    38,   87,   54,   97,   47,   76,   67,   79,   76,   92,
 /*   120 */    31,   49,   92,   88,   58,   32,   88,   77,   32,   84,
 /*   130 */    87,   54,   40,   87,   54,   39,   19,   76,   45,   65,
 /*   140 */    76,   92,   74,   31,   92,   88,   64,   32,   88,   82,
 /*   150 */    32,   48,   26,   87,   54,  103,   90,   51,   76,   55,
 /*   160 */    76,   92,   92,   55,   92,   30,   62,    5,   88,   83,
 /*   170 */    32,    8,    7,    9,   10,   11,   12,   80,   87,   54,
 /*   180 */   105,   87,   54,   68,  107,   76,   15,  101,   76,   92,
 /*   190 */    18,  100,   92,   88,   69,   32,   88,   91,   32,   32,
 /*   200 */    87,   54,  108,   87,   54,   37,   89,   76,   44,   65,
 /*   210 */    76,   92,  112,   86,   92,   88,   73,   32,   88,   57,
 /*   220 */    32,  109,   54,   59,   93,   99,   98,   16,   76,   75,
 /*   230 */    99,   98,   92,  109,   54,  111,  106,   81,   32,   60,
 /*   240 */    76,   71,   72,  178,   92,  114,   16,  113,  106,  178,
 /*   250 */    32,   87,   54,   36,   24,   23,  178,  178,   76,   24,
 /*   260 */    23,  178,   92,   87,   54,   35,   88,  178,   32,   56,
 /*   270 */    76,  178,  178,  178,   92,  178,  178,  178,   88,  178,
 /*   280 */    32,    8,    7,    9,   10,   11,   12,  178,  178,  178,
 /*   290 */    61,  178,   71,   72,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,   41,    1,    2,    3,    4,   27,
 /*    10 */    28,   29,   30,   20,   21,    1,   17,   18,   25,   26,
 /*    20 */    27,   28,   29,   30,    1,    2,    3,    4,   49,   50,
 /*    30 */    51,   32,   33,   64,   65,   42,   32,   33,   17,   18,
 /*    40 */    41,   37,   43,   39,    1,   41,    1,    1,    2,    3,
 /*    50 */     4,    1,   20,   21,    1,   32,   33,   25,   26,   27,
 /*    60 */    28,   29,   30,   63,   41,   14,    1,    2,    3,    4,
 /*    70 */    47,    2,    3,    4,   42,   53,   63,   55,   32,   33,
 /*    80 */    58,   59,   60,   61,   62,   63,    1,   44,   42,   52,
 /*    90 */    53,   16,   41,   47,   43,   42,   59,   32,   33,   60,
 /*   100 */    63,   32,   33,   66,   67,   68,   69,   55,   52,   53,
 /*   110 */    54,   52,   53,   54,   51,   59,    1,   42,   59,   63,
 /*   120 */    16,   57,   63,   67,   53,   69,   67,   65,   69,   44,
 /*   130 */    52,   53,   54,   52,   53,   54,   43,   59,   64,   65,
 /*   140 */    59,   63,   55,   16,   63,   67,   42,   69,   67,   55,
 /*   150 */    69,   52,   53,   52,   53,   54,   13,   59,   59,   14,
 /*   160 */    59,   63,   63,   14,   63,   56,   57,   21,   67,   42,
 /*   170 */    69,   25,   26,   27,   28,   29,   30,   13,   52,   53,
 /*   180 */    54,   52,   53,   54,   13,   59,   16,   13,   59,   63,
 /*   190 */    41,   13,   63,   67,   15,   69,   67,   67,   69,   69,
 /*   200 */    52,   53,   54,   52,   53,   54,   13,   59,   64,   65,
 /*   210 */    59,   63,   42,   13,   63,   67,    1,   69,   67,    1,
 /*   220 */    69,   52,   53,    1,    2,    3,    4,    1,   59,   42,
 /*   230 */     3,    4,   63,   52,   53,   66,   67,   42,   69,   15,
 /*   240 */    59,   17,   18,   70,   63,    0,    1,   66,   67,   70,
 /*   250 */    69,   52,   53,   54,   32,   33,   70,   70,   59,   32,
 /*   260 */    33,   70,   63,   52,   53,   54,   67,   70,   69,   47,
 /*   270 */    59,   70,   70,   70,   63,   70,   70,   70,   67,   70,
 /*   280 */    69,   25,   26,   27,   28,   29,   30,   70,   70,   70,
 /*   290 */    15,   70,   17,   18,
};
#define YY_SHIFT_USE_DFLT (-38)
#define YY_SHIFT_MAX 63
static const short yy_shift_ofst[] = {
 /*     0 */   226,   -1,   46,    4,    4,    4,    4,    4,    4,    4,
 /*    10 */     4,    4,    4,    4,   23,  222,   65,   69,   53,   85,
 /*    20 */    14,   45,   50,  227,  227,  275,   51,  224,  245,   21,
 /*    30 */    43,   14,  115,   93,   93,   -7,   32,  146,  256,  -18,
 /*    40 */   -18,  149,   75,  170,  127,  104,  143,  143,  164,  171,
 /*    50 */   174,  178,  193,  200,  145,  215,  218,  -37,  145,  179,
 /*    60 */   187,  195,  171,  179,
};
#define YY_REDUCE_USE_DFLT (-32)
#define YY_REDUCE_MAX 34
static const short yy_reduce_ofst[] = {
 /*     0 */   -21,   22,   37,  199,  211,   56,   59,   78,   81,  101,
 /*    10 */   126,  129,  148,  151,  169,  181,   99,   98,  144,  109,
 /*    20 */    74,  130,  -31,    0,   13,   39,   52,   39,   63,   39,
 /*    30 */    64,   62,   71,   87,   94,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   176,  176,  176,  176,  176,  176,  176,  176,  176,  176,
 /*    10 */   176,  176,  176,  176,  176,  176,  176,  176,  176,  176,
 /*    20 */   176,  176,  176,  176,  176,  176,  140,  176,  176,  176,
 /*    30 */   176,  176,  156,  176,  159,  176,  176,  168,  169,  171,
 /*    40 */   170,  176,  176,  176,  176,  176,  115,  116,  176,  124,
 /*    50 */   176,  176,  176,  176,  140,  176,  176,  176,  157,  159,
 /*    60 */   176,  176,  123,  176,  148,  146,  121,  159,  175,  158,
 /*    70 */   154,  161,  162,  160,  118,  142,  139,  147,  143,  141,
 /*    80 */   117,  144,  132,  145,  122,  119,  130,  163,  164,  129,
 /*    90 */   120,  165,  138,  137,  166,  136,  135,  167,  134,  133,
 /*   100 */   128,  127,  126,  172,  125,  173,  151,  131,  174,  150,
 /*   110 */   152,  149,  153,  155,
};
#define YY_SZ_ACTTAB (int)(sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  flow_parserARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void flow_parserTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "ID",            "STRING",        "INTEGER",     
  "FLOAT",         "SYMBOL",        "INPUT",         "OUTPUT",      
  "RETURN",        "ENTRY",         "NODE",          "CONTAINER",   
  "MOUNT",         "SEMICOLON",     "DOT",           "AT",          
  "COMMA",         "EQUALS",        "COLON",         "QUESTION",    
  "OR",            "AND",           "BAR",           "CARET",       
  "AMP",           "NE",            "EQ",            "GT",          
  "LT",            "GE",            "LE",            "COMP",        
  "PLUS",          "MINUS",         "STAR",          "SLASH",       
  "PERCENT",       "BANG",          "DOLLAR",        "HASH",        
  "UMINUS",        "OPENPAR",       "CLOSEPAR",      "OPENBRA",     
  "CLOSEBRA",      "OPENSQB",       "CLOSESQB",      "TILDA",       
  "error",         "main",          "flow",          "stmt",        
  "vall",          "dtid",          "bexp",          "blck",        
  "list",          "elem",          "lblk",          "valx",        
  "eqc",           "oexp",          "rexp",          "valn",        
  "fldm",          "fldd",          "fldr",          "fldx",        
  "flda",          "fldn",        
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "main ::= flow",
 /*   1 */ "flow ::= stmt",
 /*   2 */ "flow ::= flow stmt",
 /*   3 */ "stmt ::= ID vall SEMICOLON",
 /*   4 */ "stmt ::= ID dtid OPENPAR bexp CLOSEPAR blck",
 /*   5 */ "stmt ::= ID dtid blck",
 /*   6 */ "stmt ::= stmt SEMICOLON",
 /*   7 */ "blck ::= OPENBRA list CLOSEBRA",
 /*   8 */ "blck ::= OPENBRA CLOSEBRA",
 /*   9 */ "list ::= elem",
 /*  10 */ "list ::= list elem",
 /*  11 */ "elem ::= ID blck",
 /*  12 */ "elem ::= ID lblk",
 /*  13 */ "elem ::= ID valx SEMICOLON",
 /*  14 */ "elem ::= ID eqc valx SEMICOLON",
 /*  15 */ "elem ::= ID oexp SEMICOLON",
 /*  16 */ "elem ::= ID rexp SEMICOLON",
 /*  17 */ "elem ::= elem SEMICOLON",
 /*  18 */ "lblk ::= ID blck",
 /*  19 */ "valn ::= INTEGER",
 /*  20 */ "valn ::= FLOAT",
 /*  21 */ "valn ::= PLUS valn",
 /*  22 */ "valn ::= MINUS valn",
 /*  23 */ "valx ::= STRING",
 /*  24 */ "valx ::= valn",
 /*  25 */ "vall ::= valx",
 /*  26 */ "vall ::= dtid",
 /*  27 */ "rexp ::= OPENPAR fldm CLOSEPAR",
 /*  28 */ "rexp ::= OPENPAR ID AT CLOSEPAR",
 /*  29 */ "oexp ::= dtid OPENPAR CLOSEPAR",
 /*  30 */ "oexp ::= dtid OPENPAR ID AT CLOSEPAR",
 /*  31 */ "oexp ::= dtid OPENPAR fldm CLOSEPAR",
 /*  32 */ "fldm ::= fldd",
 /*  33 */ "fldm ::= fldm COMMA fldd",
 /*  34 */ "fldd ::= ID eqc OPENPAR fldm CLOSEPAR",
 /*  35 */ "fldd ::= ID eqc fldr",
 /*  36 */ "fldr ::= vall",
 /*  37 */ "fldr ::= fldx",
 /*  38 */ "fldr ::= TILDA ID OPENPAR CLOSEPAR",
 /*  39 */ "fldr ::= TILDA ID OPENPAR flda CLOSEPAR",
 /*  40 */ "flda ::= fldr",
 /*  41 */ "flda ::= flda COMMA fldr",
 /*  42 */ "fldx ::= fldn",
 /*  43 */ "fldx ::= fldn dtid",
 /*  44 */ "fldn ::= ID AT",
 /*  45 */ "dtid ::= ID",
 /*  46 */ "dtid ::= dtid DOT ID",
 /*  47 */ "eqc ::= EQUALS",
 /*  48 */ "eqc ::= COLON",
 /*  49 */ "bexp ::= vall",
 /*  50 */ "bexp ::= fldx",
 /*  51 */ "bexp ::= HASH fldx",
 /*  52 */ "bexp ::= OPENPAR bexp CLOSEPAR",
 /*  53 */ "bexp ::= BANG bexp",
 /*  54 */ "bexp ::= bexp OR bexp",
 /*  55 */ "bexp ::= bexp AND bexp",
 /*  56 */ "bexp ::= bexp EQ bexp",
 /*  57 */ "bexp ::= bexp NE bexp",
 /*  58 */ "bexp ::= bexp GT bexp",
 /*  59 */ "bexp ::= bexp LT bexp",
 /*  60 */ "bexp ::= bexp LE bexp",
 /*  61 */ "bexp ::= bexp GE bexp",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to flow_parser and flow_parserFree.
*/
void *flow_parserAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  flow_parserARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from flow_parserAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void flow_parserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int flow_parserStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_MAX || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( j>=0 && j<YY_SZ_ACTTAB && yy_lookahead[j]==YYWILDCARD ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_MAX ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_MAX );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_SZ_ACTTAB );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   flow_parserARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   flow_parserARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 49, 1 },
  { 50, 1 },
  { 50, 2 },
  { 51, 3 },
  { 51, 6 },
  { 51, 3 },
  { 51, 2 },
  { 55, 3 },
  { 55, 2 },
  { 56, 1 },
  { 56, 2 },
  { 57, 2 },
  { 57, 2 },
  { 57, 3 },
  { 57, 4 },
  { 57, 3 },
  { 57, 3 },
  { 57, 2 },
  { 58, 2 },
  { 63, 1 },
  { 63, 1 },
  { 63, 2 },
  { 63, 2 },
  { 59, 1 },
  { 59, 1 },
  { 52, 1 },
  { 52, 1 },
  { 62, 3 },
  { 62, 4 },
  { 61, 3 },
  { 61, 5 },
  { 61, 4 },
  { 64, 1 },
  { 64, 3 },
  { 65, 5 },
  { 65, 3 },
  { 66, 1 },
  { 66, 1 },
  { 66, 4 },
  { 66, 5 },
  { 68, 1 },
  { 68, 3 },
  { 67, 1 },
  { 67, 2 },
  { 69, 2 },
  { 53, 1 },
  { 53, 3 },
  { 60, 1 },
  { 60, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 2 },
  { 54, 3 },
  { 54, 2 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  flow_parserARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* main ::= flow */
#line 45 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_ACCEPT, yymsp[0].minor.yy0); }
#line 847 "flow-parser.c"
        break;
      case 1: /* flow ::= stmt */
#line 47 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_flow, yymsp[0].minor.yy0); }
#line 852 "flow-parser.c"
        break;
      case 2: /* flow ::= flow stmt */
      case 10: /* list ::= list elem */ yytestcase(yyruleno==10);
#line 48 "flow-parser.y"
{ yygotominor.yy0 = ast->nappend(yymsp[-1].minor.yy0, yymsp[0].minor.yy0); }
#line 858 "flow-parser.c"
        break;
      case 3: /* stmt ::= ID vall SEMICOLON */
#line 50 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_stmt, yymsp[-2].minor.yy0, yymsp[-1].minor.yy0); }
#line 863 "flow-parser.c"
        break;
      case 4: /* stmt ::= ID dtid OPENPAR bexp CLOSEPAR blck */
#line 51 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_stmt, yymsp[-5].minor.yy0, yymsp[-4].minor.yy0, yymsp[0].minor.yy0, yymsp[-2].minor.yy0); }
#line 868 "flow-parser.c"
        break;
      case 5: /* stmt ::= ID dtid blck */
#line 52 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_stmt, yymsp[-2].minor.yy0, yymsp[-1].minor.yy0, yymsp[0].minor.yy0); }
#line 873 "flow-parser.c"
        break;
      case 6: /* stmt ::= stmt SEMICOLON */
      case 7: /* blck ::= OPENBRA list CLOSEBRA */ yytestcase(yyruleno==7);
      case 17: /* elem ::= elem SEMICOLON */ yytestcase(yyruleno==17);
      case 44: /* fldn ::= ID AT */ yytestcase(yyruleno==44);
      case 52: /* bexp ::= OPENPAR bexp CLOSEPAR */ yytestcase(yyruleno==52);
#line 53 "flow-parser.y"
{ yygotominor.yy0 = yymsp[-1].minor.yy0; }
#line 882 "flow-parser.c"
        break;
      case 8: /* blck ::= OPENBRA CLOSEBRA */
#line 56 "flow-parser.y"
{ yygotominor.yy0 = ast->chtype(yymsp[-1].minor.yy0, FTK_blck); }
#line 887 "flow-parser.c"
        break;
      case 9: /* list ::= elem */
#line 58 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_blck, yymsp[0].minor.yy0); }
#line 892 "flow-parser.c"
        break;
      case 11: /* elem ::= ID blck */
      case 12: /* elem ::= ID lblk */ yytestcase(yyruleno==12);
#line 61 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_elem, yymsp[-1].minor.yy0, yymsp[0].minor.yy0); }
#line 898 "flow-parser.c"
        break;
      case 13: /* elem ::= ID valx SEMICOLON */
      case 15: /* elem ::= ID oexp SEMICOLON */ yytestcase(yyruleno==15);
      case 16: /* elem ::= ID rexp SEMICOLON */ yytestcase(yyruleno==16);
#line 63 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_elem, yymsp[-2].minor.yy0, yymsp[-1].minor.yy0); }
#line 905 "flow-parser.c"
        break;
      case 14: /* elem ::= ID eqc valx SEMICOLON */
#line 64 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_elem, yymsp[-3].minor.yy0, yymsp[-1].minor.yy0); }
#line 910 "flow-parser.c"
        break;
      case 18: /* lblk ::= ID blck */
#line 69 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_lblk, yymsp[-1].minor.yy0, yymsp[0].minor.yy0); }
#line 915 "flow-parser.c"
        break;
      case 19: /* valn ::= INTEGER */
      case 20: /* valn ::= FLOAT */ yytestcase(yyruleno==20);
      case 21: /* valn ::= PLUS valn */ yytestcase(yyruleno==21);
      case 23: /* valx ::= STRING */ yytestcase(yyruleno==23);
      case 24: /* valx ::= valn */ yytestcase(yyruleno==24);
      case 25: /* vall ::= valx */ yytestcase(yyruleno==25);
      case 26: /* vall ::= dtid */ yytestcase(yyruleno==26);
      case 36: /* fldr ::= vall */ yytestcase(yyruleno==36);
      case 37: /* fldr ::= fldx */ yytestcase(yyruleno==37);
      case 42: /* fldx ::= fldn */ yytestcase(yyruleno==42);
#line 74 "flow-parser.y"
{ yygotominor.yy0 = yymsp[0].minor.yy0; }
#line 929 "flow-parser.c"
        break;
      case 22: /* valn ::= MINUS valn */
#line 77 "flow-parser.y"
{ yygotominor.yy0 = ast->negate(yymsp[0].minor.yy0); }
#line 934 "flow-parser.c"
        break;
      case 27: /* rexp ::= OPENPAR fldm CLOSEPAR */
#line 89 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_rexp, yymsp[-1].minor.yy0); }
#line 939 "flow-parser.c"
        break;
      case 28: /* rexp ::= OPENPAR ID AT CLOSEPAR */
#line 90 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_rexp, yymsp[-2].minor.yy0); }
#line 944 "flow-parser.c"
        break;
      case 29: /* oexp ::= dtid OPENPAR CLOSEPAR */
#line 91 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_oexp, yymsp[-2].minor.yy0); }
#line 949 "flow-parser.c"
        break;
      case 30: /* oexp ::= dtid OPENPAR ID AT CLOSEPAR */
#line 92 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_oexp, yymsp[-4].minor.yy0, yymsp[-2].minor.yy0); }
#line 954 "flow-parser.c"
        break;
      case 31: /* oexp ::= dtid OPENPAR fldm CLOSEPAR */
#line 93 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_oexp, yymsp[-3].minor.yy0, yymsp[-1].minor.yy0); }
#line 959 "flow-parser.c"
        break;
      case 32: /* fldm ::= fldd */
#line 95 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_fldm, yymsp[0].minor.yy0); }
#line 964 "flow-parser.c"
        break;
      case 33: /* fldm ::= fldm COMMA fldd */
      case 41: /* flda ::= flda COMMA fldr */ yytestcase(yyruleno==41);
      case 46: /* dtid ::= dtid DOT ID */ yytestcase(yyruleno==46);
#line 96 "flow-parser.y"
{ yygotominor.yy0 = ast->nappend(yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 971 "flow-parser.c"
        break;
      case 34: /* fldd ::= ID eqc OPENPAR fldm CLOSEPAR */
#line 98 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_fldd, yymsp[-4].minor.yy0, yymsp[-1].minor.yy0); }
#line 976 "flow-parser.c"
        break;
      case 35: /* fldd ::= ID eqc fldr */
#line 99 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_fldd, yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 981 "flow-parser.c"
        break;
      case 38: /* fldr ::= TILDA ID OPENPAR CLOSEPAR */
#line 103 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_fldr, yymsp[-2].minor.yy0); }
#line 986 "flow-parser.c"
        break;
      case 39: /* fldr ::= TILDA ID OPENPAR flda CLOSEPAR */
#line 104 "flow-parser.y"
{ yygotominor.yy0 = ast->nprepend(yymsp[-1].minor.yy0, yymsp[-3].minor.yy0); }
#line 991 "flow-parser.c"
        break;
      case 40: /* flda ::= fldr */
#line 106 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_fldr, yymsp[0].minor.yy0); }
#line 996 "flow-parser.c"
        break;
      case 43: /* fldx ::= fldn dtid */
#line 110 "flow-parser.y"
{ yygotominor.yy0 = ast->chtype(ast->nprepend(yymsp[0].minor.yy0, yymsp[-1].minor.yy0), FTK_fldx); }
#line 1001 "flow-parser.c"
        break;
      case 45: /* dtid ::= ID */
#line 114 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_dtid, yymsp[0].minor.yy0); }
#line 1006 "flow-parser.c"
        break;
      case 49: /* bexp ::= vall */
      case 50: /* bexp ::= fldx */ yytestcase(yyruleno==50);
#line 121 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_bexp, yymsp[0].minor.yy0); }
#line 1012 "flow-parser.c"
        break;
      case 51: /* bexp ::= HASH fldx */
      case 53: /* bexp ::= BANG bexp */ yytestcase(yyruleno==53);
#line 123 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_bexp, yymsp[-1].minor.yy0, yymsp[0].minor.yy0); }
#line 1018 "flow-parser.c"
        break;
      case 54: /* bexp ::= bexp OR bexp */
      case 55: /* bexp ::= bexp AND bexp */ yytestcase(yyruleno==55);
      case 56: /* bexp ::= bexp EQ bexp */ yytestcase(yyruleno==56);
      case 57: /* bexp ::= bexp NE bexp */ yytestcase(yyruleno==57);
      case 58: /* bexp ::= bexp GT bexp */ yytestcase(yyruleno==58);
      case 59: /* bexp ::= bexp LT bexp */ yytestcase(yyruleno==59);
      case 60: /* bexp ::= bexp LE bexp */ yytestcase(yyruleno==60);
      case 61: /* bexp ::= bexp GE bexp */ yytestcase(yyruleno==61);
#line 126 "flow-parser.y"
{ yygotominor.yy0 = ast->node(FTK_bexp, yymsp[-2].minor.yy0, yymsp[-1].minor.yy0, yymsp[0].minor.yy0); }
#line 1030 "flow-parser.c"
        break;
      default:
      /* (47) eqc ::= EQUALS */ yytestcase(yyruleno==47);
      /* (48) eqc ::= COLON */ yytestcase(yyruleno==48);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  flow_parserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
#line 41 "flow-parser.y"

    ast->node(FTK_SYNTAX_ERROR, (int) ast->store.size());
#line 1083 "flow-parser.c"
  flow_parserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  flow_parserARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 35 "flow-parser.y"

    ast->node(FTK_SYNTAX_ERROR, (int) ast->store.size());
#line 1101 "flow-parser.c"
  flow_parserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  flow_parserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
#line 38 "flow-parser.y"

    //std::cerr << "parsed just fine, ast size: " << ast->store.size() << " root: " << ast->store.back().children[0] << "\n";
#line 1123 "flow-parser.c"
  flow_parserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "flow_parserAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void flow_parser(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  flow_parserTOKENTYPE yyminor       /* The value for the token */
  flow_parserARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  flow_parserARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
