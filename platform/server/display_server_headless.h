/*************************************************************************/
/*  display_server_headless.h                                            */
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

#ifndef DISPLAY_SERVER_HEADLESS_H
#define DISPLAY_SERVER_HEADLESS_H

#include "servers/display_server.h"

#include "core/input/input.h"
#include "drivers/unix/os_unix.h"
#include "servers/rendering/rasterizer.h"
#include "servers/rendering_server.h"

class DisplayServerHeadless : public DisplayServer {
public:
	DisplayServerHeadless(const String string, Error &error);
	bool has_feature(Feature p_feature) const override;
	String get_name() const override;
	void alert(const String &p_alert, const String &p_title) override;
	int get_screen_count() const override;
	Point2i screen_get_position(int p_screen) const override;
	Size2i screen_get_size(int p_screen) const override;
	Rect2i screen_get_usable_rect(int p_screen) const override;
	int screen_get_dpi(int p_screen) const override;
	Vector<DisplayServer::WindowID> get_window_list() const override;
	WindowID get_window_at_screen_position(const Point2i &p_position) const override;
	void window_attach_instance_id(ObjectID p_instance, WindowID p_window) override;
	ObjectID window_get_attached_instance_id(WindowID p_window) const override;
	void window_set_rect_changed_callback(const Callable &p_callable, WindowID p_window) override;
	void window_set_window_event_callback(const Callable &p_callable, WindowID p_window) override;
	void window_set_input_event_callback(const Callable &p_callable, WindowID p_window) override;
	void window_set_input_text_callback(const Callable &p_callable, WindowID p_window) override;
	void window_set_drop_files_callback(const Callable &p_callable, WindowID p_window) override;
	void window_set_title(const String &p_title, WindowID p_window) override;
	int window_get_current_screen(WindowID p_window) const override;
	void window_set_current_screen(int p_screen, WindowID p_window) override;
	Point2i window_get_position(WindowID p_window) const override;
	void window_set_position(const Point2i &p_position, WindowID p_window) override;
	void window_set_transient(WindowID p_window, WindowID p_parent) override;
	void window_set_max_size(const Size2i p_size, WindowID p_window) override;
	Size2i window_get_max_size(WindowID p_window) const override;
	void window_set_min_size(const Size2i p_size, WindowID p_window) override;
	Size2i window_get_min_size(WindowID p_window) const override;
	void window_set_size(const Size2i p_size, WindowID p_window) override;
	Size2i window_get_size(WindowID p_window) const override;
	Size2i window_get_real_size(WindowID p_window) const override;
	void window_set_mode(WindowMode p_mode, WindowID p_window) override;
	WindowMode window_get_mode(WindowID p_window) const override;
	bool window_is_maximize_allowed(WindowID p_window) const override;
	void window_set_flag(WindowFlags p_flag, bool p_enabled, WindowID p_window) override;
	bool window_get_flag(WindowFlags p_flag, WindowID p_window) const override;
	void window_request_attention(WindowID p_window) override;
	void window_move_to_foreground(WindowID p_window) override;
	bool window_can_draw(WindowID p_window) const override;
	bool can_any_window_draw() const override;
	void process_events() override;

	static void register_dummy_driver();

	static DisplayServer *create_func(const String &p_rendering_driver, WindowMode p_mode, uint32_t p_flags, const Vector2i &p_resolution, Error &r_error);

	static Vector<String> get_rendering_drivers_func();
};

#endif