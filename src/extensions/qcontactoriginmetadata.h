/*
 * Copyright (C) 2013 Jolla Ltd. <mattthew.vogt@jollamobile.com>
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Nemo Mobile nor the names of its contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 */

#ifndef QCONTACTORIGINMETADATA_H
#define QCONTACTORIGINMETADATA_H

#include "qtcontacts-extensions-config.h"

#include <QContactDetail>
#include <QContactDetailFilter>

#ifdef USING_QTPIM
QT_BEGIN_NAMESPACE_CONTACTS
#elif defined(USING_QTMOBILITY)
QTM_BEGIN_NAMESPACE
#else
#error "QtContacts variant in use is not specified"
#endif

class QContactOriginMetadata : public QContactDetail
{
public:
#ifdef USING_QTPIM
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactOriginMetadata)

    enum {
        FieldId = 0,
        FieldGroupId = 1,
        FieldEnabled = 2
    };
#else
    // Keep the existing string values to maintain DB compatibility
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactOriginMetadata, "TpMetadata")
    Q_DECLARE_LATIN1_CONSTANT(FieldId, "ContactId");
    Q_DECLARE_LATIN1_CONSTANT(FieldGroupId, "AccountId");
    Q_DECLARE_LATIN1_CONSTANT(FieldEnabled, "AccountEnabled");
#endif

    void setId(const QString &s);
    QString id() const;

    void setGroupId(const QString &s);
    QString groupId() const;

    void setEnabled(bool b);
    bool enabled() const;

    static QContactDetailFilter matchId(const QString &s);
    static QContactDetailFilter matchGroupId(const QString &s);
};

#ifdef USING_QTPIM
QT_END_NAMESPACE_CONTACTS
#else
QTM_END_NAMESPACE
#endif

#endif
