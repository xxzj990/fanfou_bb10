import bb.cascades 1.3
import bb.system 1.2
import QtQuick 1.0
import "controls"

Page {
    id: loginPage
    objectName: "loginPage"
    titleBar: TitleBar {
        id: title
        title: qsTr("登录/注册") + Retranslate.onLocaleOrLanguageChanged
    }

    // when c++ login OK,call this method
    function loginSuccess(msg) {
        // Stop loading
        progressIndicator.active = false
        progressIndicator.visible = false

        // Show success toast
        loginSuccessToast.show()
    }

    // when c++ login failed,call this method
    function loginFailed(msg) {
        // Stop loading
        progressIndicator.active = false
        progressIndicator.visible = false

        // Show toast
        showToast(qsTr("登录失败"))
    }

    // Show toast
    function showToast(msg) {
        toast.body = msg
        toast.show()
    }

    // Login action
    function loginReq() {
        // Verify input
        var nametext = username.text.trim()
        var pwdtext = password.text.trim()
        if (nametext == "" || pwdtext == "") {
            showToast(qsTr("请输入用户名和密码"))
            return
        }

        // Show loading
        progressIndicator.active = true
        progressIndicator.visible = true

        // Login
        _fanfou.login(nametext, pwdtext)
    }

    Component.onCompleted: {
        // Connect c++ with js
        _fanfou.loginSuccess.connect(loginSuccess)
        _fanfou.loginFailed.connect(loginFailed)
    }

    Container {
        layout: DockLayout {
        }

        Container {
            layout: StackLayout {
            }

            Divider {
                accessibility.name: "top line"
            }

            TextField {
                id: username
                hintText: qsTr("用户名或邮箱") + Retranslate.onLocaleOrLanguageChanged
                horizontalAlignment: HorizontalAlignment.Center
                topMargin: ui.du(5)
            }

            TextField {
                id: password
                hintText: qsTr("密码") + Retranslate.onLocaleOrLanguageChanged
                horizontalAlignment: HorizontalAlignment.Center
                topMargin: ui.du(2)
                inputMode: TextFieldInputMode.Password
                verticalAlignment: VerticalAlignment.Center

                input {
                    submitKey: SubmitKey.EnterKey
                    onSubmitted: {
                        loginReq()
                    }
                }

            }

            Button {
                id: login
                text: qsTr("登录") + Retranslate.onLocaleOrLanguageChanged
                horizontalAlignment: HorizontalAlignment.Center
                topMargin: ui.du(5)

                onClicked: {
                    loginReq()
                }
            }
        }

        LoadingActivity {
            id: progressIndicator
            active: false
            visible: false
            verticalAlignment: VerticalAlignment.Fill
            horizontalAlignment: HorizontalAlignment.Fill
        }

        attachedObjects: [
            SystemToast {
                id: toast
            },
            SystemToast {
                id: loginSuccessToast
                body: qsTr("登录成功")
                onFinished: {
                    // Close login page
                    homePane.pop()

                    // Remove login action
                    if (_fanfou.isLogin()) {
                        homePane.removeLoginAction()
                    }
                }
            }
        ]

    }

    paneProperties: NavigationPaneProperties {
        backButton: ActionItem {
            onTriggered: {
                homePane.pop()
            }
        }
    }

}
