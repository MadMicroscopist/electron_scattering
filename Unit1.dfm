object Form1: TForm1
  Left = 41
  Top = 112
  Width = 983
  Height = 694
  Caption = #1056#1072#1089#1089#1077#1103#1085#1080#1077
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 208
    Width = 42
    Height = 13
    Caption = #1069#1085#1077#1088#1075#1080#1103
  end
  object Label2: TLabel
    Left = 64
    Top = 224
    Width = 13
    Height = 13
    Caption = #1101#1042
  end
  object Label3: TLabel
    Left = 120
    Top = 208
    Width = 37
    Height = 13
    Caption = #1055#1088#1086#1073#1077#1075
  end
  object Label4: TLabel
    Left = 176
    Top = 224
    Width = 14
    Height = 13
    Caption = #1085#1084
  end
  object Label5: TLabel
    Left = 8
    Top = 248
    Width = 63
    Height = 13
    Caption = #1044#1077#1089#1089#1080#1087#1072#1094#1080#1103
  end
  object Label6: TLabel
    Left = 64
    Top = 272
    Width = 32
    Height = 13
    Caption = #1101#1042'/'#1085#1084
  end
  object Label7: TLabel
    Left = 176
    Top = 272
    Width = 13
    Height = 13
    Caption = #1101#1042
  end
  object Label8: TLabel
    Left = 8
    Top = 344
    Width = 69
    Height = 13
    Caption = #1063#1080#1089#1083#1086' '#1095#1072#1089#1090#1080#1094
  end
  object Label9: TLabel
    Left = 8
    Top = 392
    Width = 87
    Height = 13
    Caption = #1059#1075#1086#1083' '#1086#1090#1082#1083#1086#1085#1077#1085#1080#1103
  end
  object Label10: TLabel
    Left = 8
    Top = 440
    Width = 70
    Height = 13
    Caption = #1059#1075#1086#1083' '#1087#1072#1076#1077#1085#1080#1103
  end
  object Label11: TLabel
    Left = 64
    Top = 408
    Width = 23
    Height = 13
    Caption = #1075#1088#1072#1076
  end
  object Label12: TLabel
    Left = 64
    Top = 456
    Width = 23
    Height = 13
    Caption = #1075#1088#1072#1076
  end
  object PaintBox1: TPaintBox
    Left = 256
    Top = 8
    Width = 713
    Height = 345
    Color = clWhite
    ParentColor = False
  end
  object Label15: TLabel
    Left = 8
    Top = 296
    Width = 122
    Height = 13
    Caption = #1042#1077#1088#1086#1103#1090#1085#1086#1089#1090#1100' '#1088#1072#1089#1089#1077#1103#1085#1080#1103
  end
  object Label16: TLabel
    Left = 64
    Top = 320
    Width = 8
    Height = 13
    Caption = '%'
  end
  object Label17: TLabel
    Left = 112
    Top = 512
    Width = 75
    Height = 13
    Caption = 'Stopping Power'
  end
  object Label19: TLabel
    Left = 112
    Top = 568
    Width = 38
    Height = 13
    Caption = 'BS yield'
  end
  object Label13: TLabel
    Left = 8
    Top = 488
    Width = 118
    Height = 13
    Caption = #1055#1086#1083#1091#1096#1080#1088#1080#1085#1072' '#1076#1077#1090#1077#1082#1090#1086#1088#1072
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 16
    Width = 153
    Height = 89
    Caption = #1052#1086#1076#1077#1083#1100
    TabOrder = 0
    object RadioButton1: TRadioButton
      Left = 8
      Top = 24
      Width = 105
      Height = 25
      Caption = #1041#1080#1083#1100#1103#1088#1076' '#1074' '#1078#1077#1083#1077
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 56
      Width = 137
      Height = 25
      Caption = #1055#1083#1072#1089#1090#1080#1083#1080#1085#1086#1074#1099#1077' '#1096#1072#1088#1099
      TabOrder = 1
      OnClick = RadioButton2Click
    end
  end
  object Edit1: TEdit
    Left = 8
    Top = 224
    Width = 49
    Height = 21
    TabOrder = 1
    Text = '500'
  end
  object Edit2: TEdit
    Left = 120
    Top = 224
    Width = 49
    Height = 21
    TabOrder = 2
    Text = '15'
  end
  object Edit3: TEdit
    Left = 8
    Top = 264
    Width = 49
    Height = 21
    TabOrder = 3
    Text = '1'
  end
  object Edit4: TEdit
    Left = 120
    Top = 264
    Width = 49
    Height = 21
    Enabled = False
    TabOrder = 4
    Text = '50'
  end
  object Edit5: TEdit
    Left = 8
    Top = 360
    Width = 49
    Height = 21
    TabOrder = 5
    Text = '500'
  end
  object Edit6: TEdit
    Left = 8
    Top = 408
    Width = 49
    Height = 21
    TabOrder = 6
    Text = '30'
  end
  object Edit7: TEdit
    Left = 8
    Top = 456
    Width = 49
    Height = 21
    TabOrder = 7
    Text = '0'
  end
  object Button1: TButton
    Left = 0
    Top = 536
    Width = 89
    Height = 25
    Caption = #1055#1086#1085#1077#1089#1083#1072#1089#1100
    TabOrder = 8
    OnClick = Button1Click
  end
  object Edit9: TEdit
    Left = 112
    Top = 536
    Width = 73
    Height = 21
    TabOrder = 9
    Text = '0'
  end
  object Edit10: TEdit
    Left = 8
    Top = 312
    Width = 49
    Height = 21
    Enabled = False
    TabOrder = 10
    Text = '30'
  end
  object TrackBar1: TTrackBar
    Left = 88
    Top = 312
    Width = 161
    Height = 33
    Enabled = False
    Max = 100
    Min = 1
    Orientation = trHorizontal
    Frequency = 1
    Position = 30
    SelEnd = 0
    SelStart = 0
    TabOrder = 11
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 120
    Width = 201
    Height = 81
    Caption = #1058#1086#1083#1097#1080#1085#1072' '#1086#1073#1088#1072#1079#1094#1072
    TabOrder = 12
    object Label18: TLabel
      Left = 72
      Top = 48
      Width = 14
      Height = 13
      Caption = #1085#1084
    end
    object RadioButton3: TRadioButton
      Left = 8
      Top = 24
      Width = 81
      Height = 17
      Caption = #1050#1086#1085#1077#1095#1085#1072
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 96
      Top = 24
      Width = 97
      Height = 17
      Caption = #1041#1077#1089#1082#1086#1085#1077#1095#1085#1072
      TabOrder = 1
      OnClick = RadioButton4Click
    end
    object Edit11: TEdit
      Left = 8
      Top = 48
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '100'
    end
  end
  object Edit12: TEdit
    Left = 112
    Top = 584
    Width = 81
    Height = 21
    TabOrder = 13
    Text = '1'
  end
  object Edit8: TEdit
    Left = 8
    Top = 504
    Width = 49
    Height = 21
    TabOrder = 14
    Text = '50'
  end
  object Memo1: TMemo
    Left = 280
    Top = 376
    Width = 409
    Height = 201
    Lines.Strings = (
      'Memo1')
    TabOrder = 15
    OnChange = Memo1Change
  end
end
