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

#ifndef DOC_STATE_H
#define DOC_STATE_H
#include <QString>
class DocState
{
public:
    void set_edited(bool val);
    bool get_is_edited() const;

    const QString get_string() const;
    void set_string(const QString &str);
    const QString get_path() const;
    void set_path(const QString &str);

private:
    bool is_edited{false};
    QString doc;
    QString path;
};
#endif // DOC_STATE_H
