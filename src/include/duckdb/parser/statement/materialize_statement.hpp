//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/statement/materialize_statement.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/parsed_data/materialize_info.hpp"
#include "duckdb/parser/sql_statement.hpp"

namespace duckdb {

	class MaterializeStatement : public SQLStatement {
		public:
			static constexpr const StatementType TYPE = StatementType::MATERIALIZE_STATEMENT;

		public:
			MaterializeStatement();

			unique_ptr<MaterializeInfo> info;

		protected:
			MaterializeStatement(const MaterializeStatement &other);

		public:
			unique_ptr<SQLStatement> Copy() const override;
			string ToString() const override;
	};

} // namespace duckdb
