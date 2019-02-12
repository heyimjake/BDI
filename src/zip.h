/**
 * BetterDiscord Installer
 * Copyright (c) 2018-present Jiiks/JsSucks - https://github.com/Jiiks / https://github.com/JsSucks
 * All rights reserved.
 * https://betterdiscord.net
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
*/

#pragma once

#include <QString>
#include <QObject>
#include <QtCore/QProcess>

#include "logger.h"

class Zip final : public QObject {
	Q_OBJECT
public:
	Zip(const QString &in, const QString &out);
	void extract();

private:
	QString _in;
	QString _out;

#if defined(Q_OS_WIN)
	QString _extractProgram = "7z.exe";
#else
#endif

signals:
	void extractProcessChanged(const QString &standardOutput);
	void extracted(bool success);
};
