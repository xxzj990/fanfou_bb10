/* Copyright (c) 2012, 2013  BlackBerry Limited.
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

import bb.cascades 1.3
/**
*  This is a custom control to display network activity
*
*  You will learn how to:
*  -- Create a custom control
*  -- Create an ActivityIndicator
*  -- Create custom properties for setting the title, starting and stoping the ActivityIndicator
**/
Container {
    id: loadingActivity

    property alias active: activityIndicator.running

    layout: DockLayout {}

    background: Color.create("#aa000000")

    Container {
        horizontalAlignment: HorizontalAlignment.Center
        verticalAlignment: VerticalAlignment.Center

        ActivityIndicator {
            id: activityIndicator

            horizontalAlignment: HorizontalAlignment.Center

            preferredHeight: ui.du(10)
            preferredWidth: ui.du(10)
            accessibility.name: "loading"
        }
    }
}
