#include "duckdb/parser/statement/materialize_statement.hpp"
#include "duckdb/parser/expression/collate_expression.hpp"
#include "duckdb/parser/transformer.hpp"
#include "duckdb/catalog/catalog_entry/table_column_type.hpp"

namespace duckdb {

	unique_ptr<SQLStatement> Transformer::TransformMaterialize(duckdb_libpgquery::PGMaterializeStmt &stmt) {

		auto result = make_uniq<MaterializeStatement>();
		auto info = make_uniq<MaterializeInfo>();

		auto table = TransformFrom(stmt.fromClause);
		info->table_name = std::move(table);


		// Extract field definition
		auto node = stmt.fieldname;
		auto col_def = PGPointerCast<duckdb_libpgquery::PGColumnDef>(node);
		auto col_entry = TransformColumnDefinition(*col_def);
    	info->field_name = make_uniq<ColumnDefinition>(std::move(col_entry));

		// Extract JSON data column name

		// auto col_name = make_uniq<RemoveColumnInfo>(std::move(data), command->name, command->missing_ok,

		info->data_column = stmt.column;

		result->info = std::move(info);

		return result;

	}
}
