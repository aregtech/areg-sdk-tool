#ifndef LUSAN_APPLICATION_SI_SICONSTANT_HPP
#define LUSAN_APPLICATION_SI_SICONSTANT_HPP
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
 *  \file        lusan/view/si/SIConstant.hpp
 *  \ingroup     Lusan - GUI Tool for AREG SDK
 *  \author      Artak Avetyan
 *  \brief       Lusan application, Service Interface Overview section.
 *
 ************************************************************************/

/************************************************************************
 * Includes
 ************************************************************************/
#include <QScrollArea>
#include "lusan/view/common/IEDataTypeConsumer.hpp"

/************************************************************************
 * Dependencies
 ************************************************************************/
namespace Ui {
    class SIConstant;
}
    
class QTableWidgetItem;

class ConstantEntry;
class DataTypesModel;
class SIConstantDetails;
class SIConstantList;
class SIConstantModel;
class TableCell;

//////////////////////////////////////////////////////////////////////////
// SIConstantWidget class declaration
//////////////////////////////////////////////////////////////////////////

/**
 * \brief   The widget to display the constant details.
 **/
class SIConstantWidget  : public QWidget
{
    friend class SIConstant;

    Q_OBJECT

public:
    explicit SIConstantWidget(QWidget* parent);

private:
    Ui::SIConstant* ui;
};


//////////////////////////////////////////////////////////////////////////
// SIConstant class declaration
//////////////////////////////////////////////////////////////////////////

/**
 * \brief   The widget to display the constant details.
 **/
class SIConstant    : public QScrollArea
                    , public IEDataTypeConsumer
{
    Q_OBJECT

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Initializes the SIConstant object.
     * \param   model   The model of the constant.
     * \param   parent  The parent widget.
     **/
    explicit SIConstant(SIConstantModel& model, QWidget* parent = nullptr);

    virtual ~SIConstant(void);
    
protected:

    virtual void dataTypeConverted(DataTypeCustom* oldType, DataTypeCustom* newType)  override;

    virtual void dataTypeCreated(DataTypeCustom * dataType) override;

    virtual void dataTypeRemoved(DataTypeCustom* dataType) override;

    virtual void dataTypeUpdated(DataTypeCustom* dataType) override;

//////////////////////////////////////////////////////////////////////////
// Slots
//////////////////////////////////////////////////////////////////////////
protected slots:

    /**
     * \brief   Triggered when the current cell is changed.
     * \param   currentRow      The current row index.
     * \param   currentColumn   The current column index.
     * \param   previousRow     The previous row index.
     * \param   previousColumn  The previous column index.
     **/
    void onCurCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    /**
     * \brief   Triggered when the add button is clicked.
     **/
    void onAddClicked(void);

    /**
     * \brief   Triggered when the remove button is clicked.
     **/
    void onRemoveClicked(void);

    /**
     * \brief   Triggered when the insert button is clicked.
     **/
    void onInsertClicked(void);

    /**
     * \brief   Triggered when the move up button is clicked.
     * \param   newName     The new name of the constant object.
     **/
    void onNameChanged(const QString& newName);

    /**
     * \brief   Triggered when the type is changed.
     * \param   newType The new type of the constant.
     **/
    void onTypeChanged(const QString& newType);

    /**
     * \brief   Triggered when the value is changed.
     * \param   newValue    The new value of the constant.
     **/
    void onValueChanged(const QString& newValue);

    /**
     * \brief   Triggered when the cell editor data is changed.
     * \param   index       The index of the cell.
     * \param   newValue    The new value of the cell.
     **/
    void onEditorDataChanged(const QModelIndex &index, const QString &newValue);

    /**
     * \brief   Triggered when the deprecated flag is changed.
     * \param   isChecked   The flag to indicate if the constant is deprecated.
     **/
    void onDeprectedChecked(bool isChecked);

    /**
     * \brief   Triggered when the deprecation hint is changed.
     * \param   newText The new deprecation hint.
     **/
    void onDeprecateHintChanged(const QString& newText);

    /**
     * \brief   Triggered when the description is changed.
     **/
    void onDescriptionChanged(void);

//////////////////////////////////////////////////////////////////////////
// Hidden methods
//////////////////////////////////////////////////////////////////////////
private:

    /**
     * \brief   Initializes the SIConstant object.
     **/
    void updateData(void);

    /**
     * \brief   Updates the widgets.
     **/
    void updateWidgets(void);

    /**
     * \brief   Initializes the signals.
     **/
    void setupSignals(void);

    /**
     * \brief   Blocks the basic signals.
     * \param   doBlock     If true, blocks the signals, otherwise unblocks.
     **/
    void blockBasicSignals(bool doBlock);

    /**
     * \brief   Triggered when the cell data is changed to update other controls.
     **/
    void cellChanged(int row, int col, const QString& newValue);

    /**
     * \brief   Finds and returns valid pointer to the constant entry in the specified row.
     * \param   row     The row index of the constant entry.
     **/
    inline ConstantEntry* _findConstant(int row);
    inline const ConstantEntry* _findConstant(int row) const;

//////////////////////////////////////////////////////////////////////////
// Hidden members
//////////////////////////////////////////////////////////////////////////
private:
    SIConstantModel&    mModel;     //!< The model of the constant.
    SIConstantDetails*  mDetails;   //!< The details widget of the constant.
    SIConstantList*     mList;      //!< The list widget of the constant.
    SIConstantWidget*   mWidget;    //!< The widget of the constant.
    Ui::SIConstant&     ui;         //!< The user interface of the constant.
    DataTypesModel*     mTypeModel; //!< The model of the data types.
    TableCell*          mTableCell; //!< The table cell object.
    uint32_t            mCount;     //!< The counter to generate names.
};

#endif // LUSAN_APPLICATION_SI_SICONSTANT_HPP
