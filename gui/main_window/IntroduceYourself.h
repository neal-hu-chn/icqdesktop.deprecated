#pragma once

namespace Ui
{
    class LabelEx;
    class LineEditEx;

    class IntroduceYourself : public QWidget
    {
        Q_OBJECT
    public:
        IntroduceYourself(const QString& _aimid, const QString& _display_name, QWidget* parent);
        ~IntroduceYourself();

        private Q_SLOTS:
            void TextChanged();
            void UpdateProfile();
            void RecvResponse(int _error);
            void avatarChanged();

    private:
        LineEditEx*     first_name_edit_;
        LineEditEx*     last_name_edit_;
        QPushButton*   next_button_;
        LabelEx*        error_label_;
        QVBoxLayout *main_layout_;
        void setButtonActive(bool _is_active);
        void init(QWidget *parent);
    };
}
