#include "duckdb/parser/statement/materialize_statement.hpp"
#include "duckdb/parser/query_node/select_node.hpp"

namespace duckdb {
	MaterializeStatement::MaterializeStatement() : SQLStatement(StatementType::MATERIALIZE_STATEMENT) {}

	MaterializeStatement::MaterializeStatement(const MaterializeStatement &other) : SQLStatement(other), info(other.info->Copy()) {}

	unique_ptr<SQLStatement> MaterializeStatement::Copy() const {
		return unique_ptr<MaterializeStatement>(new MaterializeStatement(*this));
	}
	string MaterializeStatement::ToString() const {
	return info->ToString();
}

} // namespace duckdb
