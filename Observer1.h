#pragma once
#include "Object.h"
#include "Drawing.h"
#include <QWidget>
#include "ui_Observer1.h"
#include "observer.h"
#include "Service.h"
class Observer1 : public QWidget, public Observer
{
	Q_OBJECT

public:
	Observer1(Service& service, QString constelation, QString nume, TableModel* model, QWidget *parent = Q_NULLPTR);
	~Observer1();
	void BuildGui();

	void update() override;
	void show() override;
public slots:
//	void OnBtnResolveClicked();
	void OnBtnRemoveClicked();
	void OnTableClicked(const QModelIndex& index);
	void searchQuestions();
	void OnBtnAddClicked();
	void OnBtnViewClicked();
	bool OnCheckboxChecked();

private:
	Ui::Observer1 ui;
	QString constelation;
	QString name;
	int row_to_delete = -1;
	Star to_delete, to_update;
	TableModel* model;
	Service& service;
	std::string myStarname;
	std::string myStarconstelation;
	int id = 1;
};
