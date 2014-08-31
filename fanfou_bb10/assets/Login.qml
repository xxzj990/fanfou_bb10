import bb.cascades 1.3
import bb.system 1.2
import QtQuick 1.0

Page {
    id: loginPage
    objectName: "loginPage"
    titleBar: TitleBar {
        title: qsTr("登录/注册") + Retranslate.onLocaleOrLanguageChanged
    }

    // when c++ login OK,call this method
    function loginSuccess(msg) {
        console.log("login success result:" + msg)
        
        // Stop loading
        if (logining.running) {
            logining.stop()
        }
        
        // Show success toast
        loginSuccessToast.show()
    }

    // when c++ login failed,call this method
    function loginFailed(msg) {
        console.log("login failed result:" + msg)
        
        // Stop loading
        if (logining.running) {
            logining.stop()
        }
        
        // Show toast
        showToast("登录失败")
    }
    
    // Show toast
    function showToast(msg) {
        toast.body = qsTr(msg)
        toast.show()
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
                input.submitKey: SubmitKey.EnterKey
                verticalAlignment: VerticalAlignment.Center
            }

            Button {
                id: login
                text: qsTr("登录") + Retranslate.onLocaleOrLanguageChanged
                horizontalAlignment: HorizontalAlignment.Center
                topMargin: ui.du(5)

                onClicked: {
                    // Verify input
                    if(username.text == "" || password.text == "") {
                        showToast("请输入用户名和密码")
                        return
                    }
                    
                    // Show loading
                    if (!logining.running) {
                        logining.start()
                    }
                    
                    // Login
                    _fanfou.login()
                }
            }
        }
        
        ActivityIndicator {
            id: logining
            accessibility.name: "loading"
            verticalAlignment: VerticalAlignment.Center
            horizontalAlignment: HorizontalAlignment.Center
            preferredWidth: ui.du(10)
            preferredHeight: ui.du(10)
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
                console.debug("pop Login page")
                homePane.pop()
            }
        }
    }

}
