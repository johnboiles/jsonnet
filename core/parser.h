/*
Copyright 2015 Google Inc. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef JSONNET_PARSER_H
#define JSONNET_PARSER_H

#include <string>

#include "core/ast.h"
#include "core/lexer.h"
#include "core/string.h"

/** Parse a given JSON++ string.
 *
 * \param alloc Used to allocate the AST nodes.  The Allocator must outlive the
 * AST pointer returned.
 * \param file Used in error messages and embedded in the AST nodes.
 * \param input The string to be tokenized & parsed.
 * \returns The parsed abstract syntax tree.
 */
AST *jsonnet_parse(Allocator *alloc, const std::string &file, const char *input);

/** Escapes a string for JSON output.
 */
String jsonnet_unparse_escape(const String &str);

/** Outputs a number, trying to preserve precision as well as possible.
 */
std::string jsonnet_unparse_number(double v);

struct BuiltinDecl {
    String name;
    std::vector<String> params;
};

/** Returns the name of each built-in function. */
BuiltinDecl jsonnet_builtin_decl(unsigned long builtin);

/** The inverse of jsonnet_parse.  Should also produce valid JSON, if given a
 * restricted AST.
 */
std::string jsonnet_unparse_jsonnet(const AST *ast);

#endif  // JSONNET_PARSER_H
