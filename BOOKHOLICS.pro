#-------------------------------------------------
#
# Project created by QtCreator 2019-06-09T18:26:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BOOKHOLICS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp\
    login.cpp \
    delete_book.cpp \
    search_book.cpp \
    add_student.cpp \
    add_staff.cpp \
    logo.cpp \
    admin_panel.cpp \
    add_book.cpp \
    student_panel.cpp \
    staff_panel.cpp \
    delete_members.cpp \
    order_management.cpp \
    vender_details.cpp \
    about_us.cpp \
    avaliable_book.cpp \
    first_page.cpp\
    library_card.cpp \
    student_prfile.cpp \
    staff_profile.cpp \
    change_password.cpp \
    book_issue.cpp \
    book_return.cpp \
    book_issued.cpp \
    book_returned.cpp \
    book_transaction.cpp \
    ids.cpp \
    stock_verification.cpp \
    student_list.cpp \
    staff_list.cpp \
    deleted_books.cpp

HEADERS += \
    login.h \
    delete_book.h \
    search_book.h \
    add_student.h \
    add_staff.h \
    logo.h \
    admin_panel.h \
    add_book.h \
    student_panel.h \
    staff_panel.h \
    delete_members.h \
    order_management.h \
    vender_details.h \
    about_us.h \
    avaliable_book.h \
    first_page.h\
    library_card.h \
    student_prfile.h \
    staff_profile.h \
    change_password.h \
    book_issue.h \
    book_return.h \
    book_issued.h \
    book_returned.h \
    book_transaction.h \
    ids.h \
    stock_verification.h \
    student_list.h \
    staff_list.h \
    deleted_books.h

FORMS += \
    login.ui \
    delete_book.ui \
    search_book.ui \
    add_student.ui \
    add_staff.ui \
    logo.ui \
    admin_panel.ui \
    add_book.ui \
    student_panel.ui \
    staff_panel.ui \
    delete_members.ui \
    order_management.ui \
    vender_details.ui \
    about_us.ui \
    avaliable_book.ui \
    first_page.ui\
     library_card.ui \
    student_prfile.ui \
    staff_profile.ui \
    change_password.ui \
    book_issue.ui \
    book_return.ui \
    book_issued.ui \
    book_returned.ui \
    book_transaction.ui \
    stock_verification.ui \
    student_list.ui \
    staff_list.ui \
    deleted_books.ui

    RESOURCES += \
    bookholics.qrc
