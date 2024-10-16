/*****************************************************************************
 *
 *		QUERY:
 *				PGMaterializeStmt (MATERIALIZE)
 *
 *      MATERIALIZE  data  field1 INT   FROM t
 *           n/a    ColId  columnDef  from_clause
 *
 *****************************************************************************/
MaterializeStmt: MATERIALIZE ColId columnDef from_clause
				{
					PGMaterializeStmt *n = makeNode(PGMaterializeStmt);
					n->column = $2;
					n->fieldname = $3;
					n->fromClause = $4;
					$$ = (PGNode *)n;
				}
		;
