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
 *  \file        lusan/view/si/SIDataTopicDetails.hpp
 *  \ingroup     Lusan - GUI Tool for AREG SDK
 *  \author      Artak Avetyan
 *  \brief       Lusan application, Service Interface Overview section.
 *
 ************************************************************************/
#include "lusan/view/si/SIDataTopicDetails.hpp"
#include "lusan/view/si/SICommon.hpp"
#include "ui/ui_SIDataTopicDetails.h"

SIDataTopicDetails::SIDataTopicDetails(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::SIDataTopicDetails)
{
    QFont font{ this->font() };
    font.setBold(false);
    font.setItalic(false);
    font.setPointSize(10);
    this->setFont(font);
    ui->setupUi(this);
    setBaseSize(SICommon::WIDGET_WIDTH, SICommon::WIDGET_HEIGHT);
    setMinimumSize(SICommon::WIDGET_WIDTH, SICommon::WIDGET_HEIGHT);
}

QLineEdit* SIDataTopicDetails::ctrlName(void)
{
    return ui->editName;
}

QComboBox* SIDataTopicDetails::ctrlTypes(void)
{
    return ui->comboTypes;
}

QComboBox* SIDataTopicDetails::ctrlNotification(void)
{
    return ui->comboNotify;
}

QPlainTextEdit* SIDataTopicDetails::ctrlDescription(void)
{
    return ui->textDescribe;
}

QCheckBox* SIDataTopicDetails::ctrlDeprecated(void)
{
    return ui->checkDeprecated;
}

QLineEdit* SIDataTopicDetails::ctrlDeprecateHint(void)
{
    return ui->editDeprecated;
}
