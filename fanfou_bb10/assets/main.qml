/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import bb.cascades 1.0

TabbedPane {
    id: tabbedPane

    Menu.definition: MenuDefinition {
        actions: [
            ActionItem {
                title: qsTr("联系我") + Retranslate.onLocaleOrLanguageChanged
                imageSource: "asset:///images/ic_help.png"
            },
            ActionItem {
                title: qsTr("设置") + Retranslate.onLocaleOrLanguageChanged
                imageSource: "asset:///images/ic_settings.png"
                
                onTriggered: {
                    
                }
            }
        ]
    }

    Tab {
        id: home
        title: qsTr("首页") + Retranslate.onLocaleOrLanguageChanged
        imageSource: "asset:///images/ic_home.png"
        
        NavigationPane {
            id: homePane
            
            Page {
                id: splash
                actionBarAutoHideBehavior: ActionBarAutoHideBehavior.HideOnScroll
                
                titleBar: TitleBar {
                    title: qsTr("饭否") + Retranslate.onLocaleOrLanguageChanged
                }
                
                Container {
                    background: Color.White
                    horizontalAlignment: HorizontalAlignment.Fill
                    verticalAlignment: VerticalAlignment.Fill
                    layout: DockLayout {
                    
                    }
                    
                    
                    Label {
                        text: qsTr("饭否~") + Retranslate.onLocaleOrLanguageChanged
                        horizontalAlignment: HorizontalAlignment.Center
                        verticalAlignment: VerticalAlignment.Center
                        textStyle.color: Color.Black
                        textStyle.fontSizeValue: 2.0
                    }
                    
                }
                
                actions: [
                    ActionItem {
                        title: qsTr("发布") + Retranslate.onLocaleOrLanguageChanged
                        imageSource: "asset:///images/ic_compose.png"
                        ActionBar.placement: ActionBarPlacement.Signature
                    },
                    
                    ActionItem {
                        id: actionLogin
                        title: qsTr("登录") + Retranslate.onLocaleOrLanguageChanged
                        imageSource: "asset:///images/ic_done.png"
                        onTriggered: {
                            var page = loginDef.createObject();
                            homePane.push(page)
                        }                        
                        
                        attachedObjects: ComponentDefinition {
                            id: loginDef
                            source: "Login.qml"
                        }
                    }, 
                    
                    ActionItem {
                        title: qsTr("搜索") + Retranslate.onLocaleOrLanguageChanged
                        imageSource: "asset:///images/ic_search.png"
                    }
                ]
                
                onCreationCompleted: {
                    console.log("isLogined:" + _fanfou.isLogin())
                    if(_fanfou.isLogin()) {
                        homePane.removeLoginAction()
                    }
                }
            }
            
            onPopTransitionEnded: {
                page.destroy()
            }
            
            function removeLoginAction() {
                splash.removeAction(actionLogin)
                actionLogin.destroy()
            }
        }
        
    }
    
    Tab {
        id: atme
        title: qsTr("@我") + Retranslate.onLocaleOrLanguageChanged
        imageSource: "asset:///images/ic_notes.png"
    }
    
    Tab {
        id: dme
        title: qsTr("私信") + Retranslate.onLocaleOrLanguageChanged
        imageSource: "asset:///images/ic_email_dk.png"
    }
    
    Tab {
        id: profile
        title: qsTr("个人") + Retranslate.onLocaleOrLanguageChanged
        imageSource: "asset:///images/ic_contact.png"
    }
    
    Tab {
        id: about
        title: qsTr("关于") + Retranslate.onLocaleOrLanguageChanged
        imageSource: "asset:///images/ic_info.png"
    }
    
}




