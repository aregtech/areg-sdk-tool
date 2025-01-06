#ifndef LUSAN_MODEL_COMMON_DATATYPESMODEL_HPP
#define LUSAN_MODEL_COMMON_DATATYPESMODEL_HPP
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
 *  \file        lusan/model/common/DataTypesModel.hpp
 *  \ingroup     Lusan - GUI Tool for AREG SDK
 *  \author      Artak Avetyan
 *  \brief       Lusan application, Data Types Model.
 *
 ************************************************************************/

#include <QAbstractListModel>

class DataTypeBase;
class SIDataTypeData;

/**
 * \class   DataTypesModel
 * \brief   Model to manage and display data types in a QComboBox.
 **/
class DataTypesModel : public QAbstractListModel
{
    Q_OBJECT

public:
    /**
     * \brief   Constructor with initialization.
     * \param   dataTypeData    The instance of SIDataTypeData.
     * \param   parent          The parent object.
     **/
    DataTypesModel(SIDataTypeData& dataTypeData, QObject* parent = nullptr);

    DataTypesModel(SIDataTypeData& dataTypeData, const QStringList &excludes, QObject* parent = nullptr);

    DataTypesModel(SIDataTypeData& dataTypeData, const QList<DataTypeBase*> &excludes, QObject* parent = nullptr);

    void setFilter(const QStringList& excludes);

    void setFilter(const QList<DataTypeBase*>& excludes);

    void clearFilter();

    /**
     * \brief   Returns the number of rows in the model.
     * \param   parent  The parent index.
     * \return  The number of rows.
     **/
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    /**
     * \brief   Returns the data for the given role and section in the model.
     * \param   index   The index of the item.
     * \param   role    The role for which data is requested.
     * \return  The data for the given role and section.
     **/
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    DataTypeBase* getDataType(int index) const;

private:
    SIDataTypeData&         mDataTypeData;  //!< Reference to the SIDataTypeData instance.
    QList<DataTypeBase*>    mExcludeList;   //!< Filtered list of data types.

};

#endif  // LUSAN_MODEL_COMMON_DATATYPESMODEL_HPP