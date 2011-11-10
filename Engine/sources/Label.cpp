#include "Label.h"
#include "Game.h"

Label::Label(Game* game, const char* fontname, int size):
_position(0, 0),
_game(game),
_color(),
_font(NULL),
_text(NULL),
_message(NULL) {
    int len = strlen(fontname);
    char* identifier = new char[len + 16]; // additional space for the number
    sprintf(identifier, "%s:%i", fontname, size);
    
    _font = game->video()->fonts()->get(identifier);
    
    _color.r = 0x00;
    _color.g = 0x00;
    _color.b = 0x00;
}

Label::~Label() {
    if(_message != NULL) {
        delete[] _message;
    }

    if(_text != NULL) {
        delete _text;
    }
    
    if(_font != NULL) {
        _game->video()->fonts()->release(_font);
    }
}

void Label::update() {
}

void Label::draw() {
    if(_text != NULL) {
        _text->draw(_position);
    }
}

void Label::setPosition(const Vector& position) {
    _position = position;
}

void Label::setColor(const Color& color) {
    _color = color;
    
    render();
}

const char* Label::getMessage() const {
    return _message;
}

void Label::setMessage(const char* message) {
    int len = strlen(message);
    char* buffer = new char[len + 1];
    strcpy(buffer, message);
    
    if(_message != NULL) {
        delete[] _message;
    }
    _message = buffer;
    
    render();
}

void Label::render() {
    Text* tmp = _font->render(_message, _color);
    if(tmp != NULL) {
        if(_text != NULL) {
            delete _text;
        }
        _text = tmp;
    }
}
