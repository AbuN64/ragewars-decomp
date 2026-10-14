#include "span_16E000/code_80412270.h"
#include "types.h"
/* Lays out cell (row, col) of a scrolling table: copies the table's cell template, picks the header
   colours for header rows and columns and the body colours otherwise (mapping body positions past
   the headers onto the scrolled contents), offsets the cell by the widths and heights of the
   columns and rows before it (repeating the last header size beyond the headers), sets its size
   from its own column and row, points it at the content entry and gives the selected entry its
   highlight colours. */







void func_804122CC_de(Table_func_804122CC_de *table, Cell_func_804122CC_de *cell, u32 row, u32 col) {
    s32 lastCol;
    s32 lastRow;
    u32 entryCol;
    u32 entryRow;
    s32 x;
    s32 y;
    s32 n;
    s32 i;

    cell->layout = table->layout;
    cell->fg = table->fg;
    cell->bg = table->bg;
    if (col < table->headerCols) {
        entryCol = col;
        cell->fg = table->headerFg;
        cell->bg = table->headerBg;
        lastCol = -1;
        if (col != 0) {
            lastCol = col - 1;
        }
    } else {
        lastCol = -1;
        entryCol = col - table->headerCols + table->colScroll;
        if (table->headerCols != 0) {
            lastCol = col;
        }
    }
    if (row < table->headerRows) {
        entryRow = row;
        cell->fg = table->headerFg;
        cell->bg = table->headerBg;
        lastRow = -1;
        if (row != 0) {
            lastRow = row - 1;
        }
    } else {
        lastRow = -1;
        entryRow = row - table->headerRows + table->rowScroll;
        if (table->headerRows != 0) {
            lastRow = row;
        }
    }
    x = 0;
    y = 0;
    n = lastCol;
    if (table->headerCols < lastCol) {
        n = table->headerCols;
    }
    if (lastCol != -1) {
        for (i = 0; i < n; i++) {
            x += table->widths[i];
        }
    }
    n = lastRow;
    if (table->headerRows < lastRow) {
        n = table->headerRows;
    }
    if (lastRow != -1) {
        for (i = 0; i < n; i++) {
            y += table->heights[i];
        }
    }
    if (table->headerCols < lastCol) {
        x += (lastCol - table->headerCols) * table->widths[table->headerCols - 1];
    }
    if (table->headerRows < lastRow) {
        y += (lastRow - table->headerRows) * table->heights[table->headerRows - 1];
    }
    if (col < table->headerCols) {
        cell->layout.width = table->widths[col];
    } else {
        cell->layout.width = table->widths[table->headerCols - 1];
    }
    if (row < table->headerRows) {
        cell->layout.height = table->heights[row];
    } else {
        cell->layout.height = table->heights[table->headerRows - 1];
    }
    cell->content = table->contents[(entryRow * table->columns + entryCol) * 2];
    if (entryRow == table->selectedRow && entryCol == table->selectedCol) {
        cell->selectedFg = table->selectedFg;
        cell->selectedBg = table->selectedBg;
    } else {
        cell->selectedFg = cell->fg;
        cell->selectedBg = cell->bg;
    }
    cell->layout.x += x;
    cell->layout.y += y;
}
