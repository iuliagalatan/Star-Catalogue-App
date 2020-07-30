#include "Observer1.h"
#include <qheaderview.h>
#include <QIcon>
#include <QMessageBox>
#include <QModelIndex>
#include <QSortFilterProxyModel>

Observer1::Observer1(Service& service, QString constelation,  QString nume, TableModel* model, QWidget* parent)
	: QWidget(parent),
	service{ service},
	constelation{ constelation },
	name{nume},
	model{model}
	{
	ui.setupUi(this);
	setWindowTitle(nume + ": user");
	
	setWindowFlags(Qt::WindowStaysOnTopHint);
	resize(1500, 900);

	/*ui.label_2->setVisible(false);
	ui.resolveBtn->setVisible(false);*/
	
	ui.tableView->setModel(model);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableView->setColumnWidth(0, 100);
	ui.tableView->setColumnWidth(1, 300);
	ui.tableView->setColumnWidth(2, 100);
	ui.tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);

	connect(ui.searchLE, &QLineEdit::textEdited, this, &Observer1::searchQuestions);
	connect(ui.addbtn, &QPushButton::clicked, this, &Observer1::OnBtnAddClicked);
	connect(ui.pushButton, &QPushButton::clicked, this, &Observer1::OnBtnViewClicked);
	connect(ui.tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(OnTableClicked(const QModelIndex&)));
	connect(ui.checkBox, &QCheckBox::clicked, this, &Observer1::OnCheckboxChecked);
//	connect(this, &QCheckBox::clicked, model, &Observer1::OnCheckboxChecked);
	//connect(ui.removeBtn, &QPushButton::clicked, this, &Observer1::OnBtnRemoveClicked);
}

/*
Specifications:
	Function OnBtnAddClicked is used for getting the information for the star to be added
	input:-
	output:- (calls function to add from service) and checks for exceptions
*/
void Observer1::OnBtnAddClicked()
{
	std::string name = ui.nameLE->text().toStdString();
	std::string RA = ui.RALE->text().toStdString();
	std::string DEC = ui.DECLE->text().toStdString();
	std::string diameter = ui.addLineEdit->text().toStdString();



	if (name == "")
	{
		QMessageBox::warning(this, "Error", "Name cannot be empty!");
		return;
	}
	if ( stoi(diameter) <=0)
	{
		QMessageBox::warning(this, "Error", "Diameter cannot be < 0");
		return;
	}

	for (auto issue : service.GetObjects())
		if (issue.getName() == name)
		{
			QMessageBox::warning(this, "Error", "The star was already added");
			return;
		}


	Star obj{ name,constelation.toStdString(), RA,DEC, stoi(diameter) };
	
	try {
		service.AddObject(obj);
	}
	catch(std::exception& ex){
		QMessageBox::warning(this, "Exception", "The star was already added");
	}
	int rows =service.GetObjects().size();
	model->insertRows(rows - 1, 1, QModelIndex{});

}

void Observer1::OnBtnViewClicked()
{
	Drawing* d = new Drawing(service, myStarconstelation, myStarname);
	d->setWindowFlags(Qt::WindowStaysOnTopHint);
	d->resize(1500, 900);
	d->show();
}

bool Observer1::OnCheckboxChecked()
{

	if (this->ui.checkBox->isChecked() == true)
	{
		this->ui.tableView->setModel(nullptr);
		QSortFilterProxyModel* filter = new QSortFilterProxyModel{};
		filter->setSourceModel(this->model);
		filter->setFilterKeyColumn(1);
		filter->setFilterFixedString(constelation);
		this->ui.tableView->setModel(filter);
	}
	else
	{
		this->ui.tableView->setModel(model);
	}
	return false;
}

Observer1::~Observer1()
{

}

void Observer1::update()
{
	ui.tableView->viewport()->update();
}

void Observer1::show()
{
	QWidget::show();
}

void Observer1::OnBtnRemoveClicked()
{
	if (row_to_delete != -1)
	{
		model->removeRows(row_to_delete, 1);
		service.RemoveObject(to_delete);
	}
	else
		QMessageBox::warning(this, "Warning", "Can't remove an unresolved item");
		
}

void Observer1::OnTableClicked(const QModelIndex& index)
{
	int row = index.row();
	
	  myStarname = index.sibling(row, 0).data().toString().toStdString();
	myStarconstelation = index.sibling(row, 1).data().toString().toStdString();
	
	
	
}


void Observer1::searchQuestions()
{
	std::string searchString = this->ui.searchLE->text().toStdString();
	this->ui.listWidget->clear();
	auto filteredBySearchVector = service.getBySearch(searchString);

	for (auto object : filteredBySearchVector)
	{
		std::string line = object.getName() + " " + object.getConstelation() + " " + object.getRA() + " " + object.getDEC()+" ";
		this->ui.listWidget->addItem(QString::fromStdString(line));
		
	}
	

}