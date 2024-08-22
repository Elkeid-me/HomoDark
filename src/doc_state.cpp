// Copyright (C) 2022-2024 Elkeid-me
//
// This file is part of HomoDark.
//
// HomoDark is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// HomoDark is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with HomoDark.  If not, see <http://www.gnu.org/licenses/>.

#include "doc_state.h"
#include <QString>

void DocState::set_edited(bool val) { is_edited = val; }
bool DocState::get_is_edited() const { return is_edited; }

const QString DocState::get_string() const { return doc; }
void DocState::set_string(const QString &str) { doc = str; }

const QString DocState::get_path() const { return path; }
void DocState::set_path(const QString &str) { path=str; }
