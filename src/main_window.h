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

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "doc_state.h"
#include "ll_md_parser.h"
#include <QMainWindow>
#include <QList>
#include <QFile>

class MainWindowUI;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    ~MainWindow();

private slots:
    void new_document();

    void file_menu_slot();

    void close_tab(int index);

    void parse();

    void navigate_to(int index);

    void save_current();

    void save_as_current();

    void close_current();

    void open_file();

private:
    void save_file(int index);

    void save_as(int index);

    MainWindowUI* ui;

    int n_document{0}, previous_index{-1};

    QList<DocState> doc_states;

    bool sys_operation{false};

    ll_markdown::Parser parser;

    QString css;
};
#endif // MAIN_WINDOW_H
