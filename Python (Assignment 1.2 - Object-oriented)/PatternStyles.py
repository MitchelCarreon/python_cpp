from Pattern import Pattern
from BaseImage import BaseImage

import random


class Stripes(Pattern):
    def __init__(self, image):
        super().__init__(image)

    def create(self):
        super().create()
        line_pixels = self._image.size() / 10
        rgb = [0, 0, 0]

        i = 0
        while i < self._image.size():
            if i < line_pixels:
                self._image._pixels.append(BaseImage._Pixel(*rgb))
                i += 1
            else:
                line_pixels += self._image.size() / 10
                rgb[1] = 255 if rgb[1] == 0 else 0
                rgb[2] = rgb[0]


class Waves(Pattern):
    def __init__(self, image):
        super().__init__(image)

    def create(self):
        super().create()
        red = 0
        green = 255
        blue = 0

        for i in range(0, self._image.size()):
            if red > 255:
                red = 50
            else:
                red += 1

            if green <= 0:
                green = 25
            else:
                green -= 1

            if blue > 255:
                blue = 100
            else:
                blue += 1

            self._image._pixels.append(BaseImage._Pixel(red, green, blue))


class Psychedelic(Pattern):
    def __init__(self, image):
        super().__init__(image)

    def create(self):
        for i in range(0, self._image.size()):
            self._image._pixels.append(BaseImage._Pixel(
                random.randint(0, 200) % 256, random.randint(0, 100) % 256 + 50, random.randint(0, 100) % 256 + 100))
