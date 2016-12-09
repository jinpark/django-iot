from dashing.widgets import NumberWidget, GraphWidget
from .models import ButtonPress, Temperature

class ButtonUpWidget(NumberWidget):
    title = 'Up Button Pressed'

    def get_value(self):
        return ButtonPress.objects.filter(direction="up").count()

class ButtonRightWidget(NumberWidget):
    title = 'Right Button Pressed'

    def get_value(self):
        return ButtonPress.objects.filter(direction="right").count()

class ButtonDownWidget(NumberWidget):
    title = 'Down Button Pressed'

    def get_value(self):
        return ButtonPress.objects.filter(direction="down").count()

class ButtonLeftWidget(NumberWidget):
    title = 'Left Button Pressed'

    def get_value(self):
        return ButtonPress.objects.filter(direction="left").count()

class TemperatureWidget(GraphWidget):
    title = 'Temperature Widget'

    # def get_value(self):
    #     return Temperature.objects.all().order_by('-id').values('temperature')[:1]

    def get_data(self):
        latest_temps = Temperature.objects.all().order_by('-id').values('temperature')[:5]
        all_temps = []
        for i, temp in enumerate(latest_temps):
            all_temps.append({'x': i, 'y': temp['temperature']})

        return all_temps

