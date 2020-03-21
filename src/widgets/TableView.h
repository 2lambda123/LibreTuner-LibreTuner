#ifndef LIBRETUNER_TABLEVIEW_H
#define LIBRETUNER_TABLEVIEW_H

#include <QWidget>
#include <definition/table.h>

#include "VerticalLabel.h"
#include "models/TableModel.h"

class QTableView;
class QLabel;
class GraphWidget;
class QBoxLayout;

class TableView : public QWidget
{
public:
    explicit TableView(lt::Table && table, QWidget * parent = nullptr);
    ~TableView() override;

    void setTable(lt::Table && table);

    TableModel * model() { return &model_; }

private slots:
    void axesChanged();

private:
    QTableView * view_;
    QLabel * labelX_;
    VerticalLabel * labelY_;
    QBoxLayout * layout_;

    TableModel model_;
};

#endif // LIBRETUNER_TABLEVIEW_H
