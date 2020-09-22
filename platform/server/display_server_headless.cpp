/*************************************************************************/
/*  display_server_headless.cpp                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "display_server_headless.h"

#include "drivers/dummy/rasterizer_dummy.h"

bool DisplayServerHeadless::has_feature(DisplayServer::Feature p_feature) const {
	return false;
}
String DisplayServerHeadless::get_name() const {
	return String();
}
void DisplayServerHeadless::alert(const String &p_alert, const String &p_title) {
}
int DisplayServerHeadless::get_screen_count() const {
	return 0;
}
Point2i DisplayServerHeadless::screen_get_position(int p_screen) const {
	return Point2i();
}
Size2i DisplayServerHeadless::screen_get_size(int p_screen) const {
	return Size2i();
}
Rect2i DisplayServerHeadless::screen_get_usable_rect(int p_screen) const {
	return Rect2i();
}
int DisplayServerHeadless::screen_get_dpi(int p_screen) const {
	return 0;
}
Vector<DisplayServer::WindowID> DisplayServerHeadless::get_window_list() const {
	return Vector<DisplayServer::WindowID>();
}
DisplayServer::WindowID DisplayServerHeadless::get_window_at_screen_position(const Point2i &p_position) const {
	return 0;
}
void DisplayServerHeadless::window_attach_instance_id(ObjectID p_instance, DisplayServer::WindowID p_window) {
}
ObjectID DisplayServerHeadless::window_get_attached_instance_id(DisplayServer::WindowID p_window) const {
	return ObjectID();
}
void DisplayServerHeadless::window_set_rect_changed_callback(const Callable &p_callable, DisplayServer::WindowID p_window) {
}
void DisplayServerHeadless::window_set_window_event_callback(const Callable &p_callable, DisplayServer::WindowID p_window) {
}
void DisplayServerHeadless::window_set_input_event_callback(const Callable &p_callable, DisplayServer::WindowID p_window) {
}
void DisplayServerHeadless::window_set_input_text_callback(const Callable &p_callable, DisplayServer::WindowID p_window) {
}
void DisplayServerHeadless::window_set_drop_files_callback(const Callable &p_callable, DisplayServer::WindowID p_window) {
}
void DisplayServerHeadless::window_set_title(const String &p_title, DisplayServer::WindowID p_window) {
}
int DisplayServerHeadless::window_get_current_screen(DisplayServer::WindowID p_window) const {
	return 0;
}
void DisplayServerHeadless::window_set_current_screen(int p_screen, DisplayServer::WindowID p_window) {
}
Point2i DisplayServerHeadless::window_get_position(DisplayServer::WindowID p_window) const {
	return Point2i();
}
void DisplayServerHeadless::window_set_position(const Point2i &p_position, DisplayServer::WindowID p_window) {
}
void DisplayServerHeadless::window_set_transient(DisplayServer::WindowID p_window, DisplayServer::WindowID p_parent) {
}
void DisplayServerHeadless::window_set_max_size(const Size2i p_size, DisplayServer::WindowID p_window) {
}
Size2i DisplayServerHeadless::window_get_max_size(DisplayServer::WindowID p_window) const {
	return Size2i();
}
void DisplayServerHeadless::window_set_min_size(const Size2i p_size, DisplayServer::WindowID p_window) {
}
Size2i DisplayServerHeadless::window_get_min_size(DisplayServer::WindowID p_window) const {
	return Size2i();
}
void DisplayServerHeadless::window_set_size(const Size2i p_size, DisplayServer::WindowID p_window) {
}
Size2i DisplayServerHeadless::window_get_size(DisplayServer::WindowID p_window) const {
	return Size2i();
}
Size2i DisplayServerHeadless::window_get_real_size(DisplayServer::WindowID p_window) const {
	return Size2i();
}
void DisplayServerHeadless::window_set_mode(DisplayServer::WindowMode p_mode, DisplayServer::WindowID p_window) {
}
DisplayServer::WindowMode DisplayServerHeadless::window_get_mode(DisplayServer::WindowID p_window) const {
	return WINDOW_MODE_WINDOWED;
}
bool DisplayServerHeadless::window_is_maximize_allowed(DisplayServer::WindowID p_window) const {
	return false;
}
void DisplayServerHeadless::window_set_flag(DisplayServer::WindowFlags p_flag, bool p_enabled, DisplayServer::WindowID p_window) {
}
bool DisplayServerHeadless::window_get_flag(DisplayServer::WindowFlags p_flag, DisplayServer::WindowID p_window) const {
	return false;
}
void DisplayServerHeadless::window_request_attention(DisplayServer::WindowID p_window) {
}
void DisplayServerHeadless::window_move_to_foreground(DisplayServer::WindowID p_window) {
}
bool DisplayServerHeadless::window_can_draw(DisplayServer::WindowID p_window) const {
	return false;
}
bool DisplayServerHeadless::can_any_window_draw() const {
	return false;
}
void DisplayServerHeadless::process_events() {
}

Vector<String> DisplayServerHeadless::get_rendering_drivers_func() {
	Vector<String> drivers;

	drivers.push_back("dummy");

	return drivers;
}

DisplayServer *DisplayServerHeadless::create_func(const String &p_rendering_driver, WindowMode p_mode, uint32_t p_flags, const Vector2i &p_resolution, Error &r_error) {
	DisplayServer *ds = memnew(DisplayServerHeadless(p_rendering_driver, r_error));
	if (r_error != OK) {
		ds->alert("Your video card driver does not support any of the supported Vulkan versions.\n"
				  "Please update your drivers or if you have a very old or integrated GPU upgrade it.",
				"Unable to initialize Video driver");
	}
	return ds;
}

void DisplayServerHeadless::register_dummy_driver() {
	register_create_function("dummy", create_func, get_rendering_drivers_func);
}
DisplayServerHeadless::DisplayServerHeadless(const String string, Error &error) {
	RasterizerDummy::make_current();
	error = OK;
}
