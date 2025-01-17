#ifndef LUSAN_APPLICATION_SI_SIMETHOD_HPP
#define LUSAN_APPLICATION_SI_SIMETHOD_HPP
/************************************************************************
 *  This file is part of the Lusan project, an official component of the AREG SDK.
 *  Lusan is a graphical user interface (GUI) tool designed to support the development,
 *  debugging, and testing of applications built with the AREG Framework.
 *
 *  Lusan is available as free and open-source software under the MIT License,
 *  providing essential features for developers.
 *
 *  For detailed licensing terms, please refer to the LICENSE.txt file included
 *  with this distribution or contact us at info[at]aregtech.com.
 *
 *  \copyright   � 2023-2024 Aregtech UG. All rights reserved.
 *  \file        lusan/view/si/SIMethod.hpp
 *  \ingroup     Lusan - GUI Tool for AREG SDK
 *  \author      Artak Avetyan
 *  \brief       Lusan application, Service Interface Overview section.
 *
 ************************************************************************/
#include <QScrollArea>
#include "lusan/view/common/IEDataTypeConsumer.hpp"

class SIMethodBase;
class SIMethodDetails;
class SIMethodList;
class SIMethodParamDetails;
class SIMethodModel;
class QTreeWidgetItem;
class SIMethodBroadcast;
class SIMethodRequest;
class SIMethodResponse;

namespace Ui {
    class SIMethod;
}

class SIMethodWidget : public QWidget
{
    friend class SIMethod;

    Q_OBJECT

public:
    explicit SIMethodWidget(QWidget* parent);

private:
    Ui::SIMethod* ui;
};

class SIMethod  : public QScrollArea
                , public IEDataTypeConsumer
{
    Q_OBJECT

public:
    explicit SIMethod(SIMethodModel & model, QWidget* parent = nullptr);

    virtual ~SIMethod(void);

protected:

    void onNameChanged(const QString & newName);

    void onRequestSelected(bool isSelected);

    void onResponseSelected(bool isSelected);

    void onBroadcastSelected(bool isSelected);

    void onConnectedResponseChanged(int index);

    void onAddClicked(void);

    void onRemoveClicked(void);

    void onParamAddClicked(void);

    void onParamRemoveClicked(void);

    void onParamInsertClicked(void);

    void onMoveUpClicked(void);

    void onMoveDownClicked(void);

    void onCurCellChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);

private:
    /**
     * \brief Updates the data in the table.
     */
    void updateData(void);

    /**
     * \brief Updates the widgets.
     */
    void updateWidgets(void);

    /**
     * \brief Initializes the signals.
     */
    void setupSignals(void);

    /**
     * \brief Blocks the basic signals.
     * \param doBlock If true, blocks the signals, otherwise unblocks.
     */
    void blockBasicSignals(bool doBlock);

    void showParamDetails(bool show);

    void showMethodDetails(bool show);

    QTreeWidgetItem* updateMethodNode(QTreeWidgetItem* item, SIMethodBase* method);

    void selectRequest(SIMethodRequest* request);

private:
    SIMethodModel &         mModel;
    SIMethodDetails*        mDetails;
    SIMethodList*           mList;
    SIMethodParamDetails*   mParams;
    SIMethodWidget*         mWidget;
    Ui::SIMethod&           ui;

    uint32_t               mCount;
};

#endif // LUSAN_APPLICATION_SI_SIMETHOD_HPP
